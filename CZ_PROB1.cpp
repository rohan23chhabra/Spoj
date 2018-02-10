#include <bits/stdc++.h>
#define mod 1000000007
#define mp make_pair
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define ll long long
#define LLINF LLONG_MAX
#define LINF LONG_MAX
#define INF INT_MAX
#define SIZE 100005
#define ff first
#define ss second
#define X real()
#define Y imag()
#define sz(a) sizeof(a) 
using namespace std;
typedef pair<int,int> ii;
typedef complex<double> point;
int prime[1000002];
vector<int>primes;
int ar[5];
int dp[10000][10];
void sieve()
{
	memset(prime,0,sz(prime));
	prime[0]=prime[1]=1;
	for(int i=2;i*i<=1000002;i++)
	{
		if(prime[i]==1)
			continue;
		for(int j=i*i;j<=1000002;j+=i)
		{
			prime[j]=1;
		}
	}
	primes.pb(2);
	for(int i=2;i<=1000002;i++)
	{
		if(!prime[i])
		{
			if(i%4==1)
				primes.pb(i);
		}
	}
}
int solve(int sum,int i)
{
	if(sum==0)
		return 1;
	if(sum>0 && i<0)
		return 0;
	if(i<0)
	    return 0;
	if(sum<0)
		return 0;
	if(dp[sum][i]!=-1)
		return dp[sum][i];
	dp[sum][i]=solve(sum-ar[i],i)+solve(sum,i-1);
	return dp[sum][i];
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	sieve();
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int sum=primes[n-1];
		//cout<<sum<<"\n";
		for(int i=0;i<k;i++)
			ar[i]=i+1;
		memset(dp,-1,sz(dp));
		cout<<solve(sum,k-1)<<"\n";
	}
	return 0;
}