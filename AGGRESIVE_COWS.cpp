#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t,n,c;
	long ar[100000];
	cin>>t;
	while(t--)
	{
	    cin>>n>>c;
	    for(int i=0;i<n;i++)
	    {
	        cin>>ar[i];
	    }
	    sort(ar,ar+n);
	    long low=LONG_MAX;
	    for(int i=0;i<n-1;i++)
	    {
	        if((ar[i+1]-ar[i])<low)
	        {
	            low=ar[i+1]-ar[i];
	        }
	    }
	    long high=ar[n-1]-ar[0];
	    while(low<high)
	    {
	        long x=low+(high-low+1)/2;
	        int cows=1;
	        int current=0;
	        for(int i=1;i<n;i++)
	        {
	            if(ar[i]-ar[current]>=x)
	            {
	                cows++;
	                current=i;
	            }
	        }
	        if(cows<c)
	        {
	            high=x-1;
	        }
	        else
	        {
	            low=x;
	        }
	    }
	    cout<<low<<"\n";
	}
	return 0;
}
