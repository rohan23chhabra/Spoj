#include <bits/stdc++.h>
using namespace std;
int u[10005],v[10005],w[1000005];
int parent[10005],rank[10005];
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2],lu[n1],ru[n2],lv[n1],rv[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        lu[i]=u[l+i];
        lv[i]=v[l+i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
        ru[j]=u[m+1+j];
        rv[j]=v[m+1+j];
    }
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            u[k]=lu[i];
            v[k]=lv[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            u[k]=ru[j];
            v[k]=rv[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        u[k]=lu[i];
        v[k]=lv[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        u[k]=ru[j];
        v[k]=rv[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}


int find(int s)
{
	if(parent[s]==s)
	{
		return s;
	}
	return (parent[s]=find(parent[s]));//Path compression
}
void unionSet(int l1,int l2)
{
	if(rank[l1]>rank[l2])
	{
		parent[l2]=l1;
	}
	else if(rank[l2]>rank[l1])
	{
		parent[l1]=l2;
	}
	else
	{
		parent[l1]=l2;
		rank[l2]++;
	}
}

int main()
{
	int n,m;
	long long int ans=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	}
	mergeSort(w,0,m-1);
	int c=0;
	for(int i=0;i<m;i++)
	{
		int leader1=find(u[i]);
		int leader2=find(v[i]);
		if(leader1!=leader2)
		{
			unionSet(leader1,leader2);
			ans+=w[i];
			c++;
		}
		if(c==n-1)
		{
			break;
		}
	}
	printf("%lld\n",ans);
}

