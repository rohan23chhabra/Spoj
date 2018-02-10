#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t,n,m,ans,ar[1000];
	scanf("%d",&t);
	while(t--)
	{
	    ans=0;
	    scanf("%d %d",&n,&m);
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&ar[i]);
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(ar[i]>ar[m])
	        {
	            ans++;
	        }
	    }
	    int index=-1;
	    for(int i=9;i>=1;i--)
	    {
	        if(ar[m]==i)
	        {
	            break;
	        }
	        if(index==-1)
	        {
	            for(int j=n-1;j>=0;j--)
	            {
	                if(ar[j]==i)
	                {
	                    index=j;
	                    break;
	                }
	            }
	        }
	        else
	        {
	            int j=(index-1+n)%n;
	            while(j!=index)
	            {
	                if(ar[j]==i)
	                {
	                    index=j;
	                    break;
	                }
	                j=(j-1+n)%n;
	            }
	        }
	    }
	    int i=(index+1)%n;
	    while(i!=m)
	    {
	        if(ar[i]==ar[m])
	        {
	            ans++;
	        }
	        i=(i+1)%n;
	    }
	    cout<<ans+1<<"\n";
	}
	return 0;
}
