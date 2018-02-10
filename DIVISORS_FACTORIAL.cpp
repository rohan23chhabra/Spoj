#include <bits/stdc++.h>
using namespace std;
int sieve[100000];
int prime[100000];
int power[100000];
void precompute()
{
    memset(sieve,0,sizeof(sieve));
    sieve[0]=sieve[1]=1;
    for(int i=2;i*i<100000;i++)
    {
        if(sieve[i]==0)
        {
            for(int j=i*i;j<100000;j+=i)
            {
                sieve[j]=1;
            }
        }
    }
    int c=0;
    for(int i=2;i<100000;i++)
    {
        if(sieve[i]==0)
        {
            prime[c++]=i;
        }
    }
    /*for(int i=0;i<c;i++){
        printf("%d ",prime[i]);
    }
    printf("\n");*/
}
int main() 
{
    precompute();
	int t,n;
	long long int ans;
	scanf("%d",&t);
	while(t--)
	{
	    memset(power,0,sizeof(power));
	    ans=1;
	    scanf("%d",&n);
	    int i=0;
	    while((n/prime[i])!=0)
	    {
	        int temp=prime[i];
	        while((n/temp)!=0)
	        {
	            power[i]+=n/temp;
	            temp*=prime[i];
	        }
	        i++;
	    }
	    for(int j=0;j<i;j++)
	    {
	        ans=(((power[j]+1)%1000000007)*ans)%1000000007;
	    }
	    printf("%lld\n",ans);
	}
	return 0;
}
