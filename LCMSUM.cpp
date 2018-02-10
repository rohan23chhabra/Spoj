#include <bits/stdc++.h>
using namespace std;
long long int phi[1000005];
long long int sum[1000005];
void precompute()
{
	for(int i=1;i<1000005;i++)
	{
		phi[i]=i;
	}
	for(int i=2;i<1000005;i++)
	{
		if(phi[i]==i)
		{
			for(int j=i;j<1000005;j+=i)
			{
				phi[j]/=i;
				phi[j]*=i-1;
			}
		}
	}
	memset(sum,0,sizeof(sum));
	for(int i=1;i<1000005;i++)
	{
		for(int j=i;j<1000005;j+=i)
		{
			sum[j]+=i*phi[i];
		}
	}
}
int main()
{
	int t;
	long long int ans,n;
	scanf("%d",&t);
	precompute();
	while(t--)
	{
		scanf("%lld",&n);
		ans=sum[n]+1;
		ans*=n;
		ans/=2;
		printf("%lld\n",ans);
	}
	return 0;
}