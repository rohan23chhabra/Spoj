#include <bits/stdc++.h>
using namespace std;
int prime[1000005];
long long a[1000005];
void sieve()
{
	memset(prime,0,sizeof(prime));
	//prime[0]=prime[1]=1;
	for(int i=1;i<1000005;i++)
	{
		for(int j=i;j<1000005;j+=i)
		{
			prime[j]+=i;
		}
	}
	for(int i=1;i<1000005;i++)
	{
		prime[i]-=i;
	}
	a[0]=a[1]=0;
	for(int i=2;i<1000005;i++)
	{
		a[i]=a[i-1]+prime[i];
	}
}
int main()
{
	sieve();
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<a[n]<<"\n";
	}
}