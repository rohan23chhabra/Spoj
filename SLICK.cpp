#include <bits/stdc++.h>
using namespace std;
int ar[1005][1005];
int flag[1005][1005];
int size;
//map<int,int>m;
int func(int i,int j)
{
    if(ar[i][j]==0 || flag[i][j]==1)
    {
        return 0;
    }
    flag[i][j]=1;
    int s1=func(i,j-1);
    int s2=func(i-1,j);
    int s3=func(i,j+1);
    int s4=func(i+1,j);
    return (1+s1+s2+s3+s4);
}
int main() 
{
	int n,m;
	while(1)
	{
	    cin>>n>>m;
	    if(n==0 && m==0)
	    {
	        break;
	    }
	    for(int i=0;i<=n+1;i++)
	    {
	        for(int j=0;j<=m+1;j++)
	        {
	            ar[i][j]=0;
	            flag[i][j]=0;
	        }
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            cin>>ar[i][j];
	        }
	    }
	    //int p=0;
	    map<int,int>freq;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            if(ar[i][j]!=0 && !flag[i][j])
	            {
	                size=0;
	                size=func(i,j);
	                freq[size]++;
	            }
	        }
	    }
	    map<int,int>::iterator it;
	    int sum=0;
	    for(it=freq.begin();it!=freq.end();it++)
	    {
	        sum+=it->second;
	    }
	    cout<<sum<<"\n";
	    for(it=freq.begin();it!=freq.end();it++)
	    {
	        cout<<it->first<<" "<<it->second<<"\n";
	    }
	}
	return 0;
}
