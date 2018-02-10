#include <bits/stdc++.h>
using namespace std;

long long power(long a,long n)
{
    if(n==0)
    {
        return 1;
    }
    long long p=power(a,n/2)%1000000007;
    if(n%2==0)
    {
        return (p*p)%1000000007;
    }
    else
    {
        return ((p*p)%1000000007*a)%1000000007;
    }
}
long long fact[2000005];
int main() 
{
	fact[0]=1;
	fact[1]=1;
	for(int i=2;i<2000005;i++)
	{
	    fact[i]=(i*fact[i-1])%1000000007;
	}
	int t,n;
	long long ans,v1,v2;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    if(n<=0)
	    {
	        printf("0\n");
	        continue;
	    }
	    ans=fact[2*n-1];
	    //cout<<ans<<"\n";
	    v1=power(fact[n],1000000005);
	    v2=power(fact[n-1],1000000005);
	    ans=(ans*v1)%1000000007;
	    ans=(ans*v2)%1000000007;
	    ans=(ans*n)%1000000007;
	    printf("%lld\n",ans);
	}
	return 0;
}
