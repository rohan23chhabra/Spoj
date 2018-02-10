#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    float ans=n;
	    for(int i=2;i*i<=n;i++)
	    {
	        if(n%i==0)
	        {
	            
	            while(n%i==0)
	            n/=i;
	            ans*=(1.0 - (1.0 / (float) i));
	        }
	    }
	    if(n>1)
	    {
	        ans*=(1.0 - (1.0 / (float) n));
	    }
	    cout<<ans<<"\n";
	}
	
	return 0;
}
