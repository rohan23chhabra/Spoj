#include <bits/stdc++.h>
using namespace std;
int prime[1000001];
int phi[1000001];
long long sumgcd[1000001];
long long ans[1000001];
int main() 
{
    memset(prime,0,sizeof(prime));
    memset(phi,0,sizeof(phi));
    memset(sumgcd,0,sizeof(sumgcd));
    for(int i=1;i<1000001;i++) 
    {
        phi[i]=i;
    }
    for(int i=2;i<1000001;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<1000001;j+=i)
            {
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }
    }
    for(int i=1;i<1000001;i++)
    {
        for(int j=i;j<1000001;j+=i)
        {
            sumgcd[j]+=1LL*i*phi[j/i];
        }
    }
    for(int i=1;i<1000001;i++)
    {
        sumgcd[i]-=i;
    }
    ans[0]=0;
    for(int i=1;i<1000001;i++)
    {
        ans[i]=ans[i-1]+sumgcd[i];
    }
	int n;
	while(1)
	{
	    scanf("%d",&n);
	    if(n==0)
	    {
	        break;
	    }
	    printf("%lld\n",ans[n]);
	}
	return 0;
}
