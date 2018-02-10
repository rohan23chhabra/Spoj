#include <bits/stdc++.h>
#define mod 1000000007
#define mp make_pair
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define ll long long
#define LLINF LLONG_MAX
#define LINF LONG_MAX
#define INF INT_MAX
#define SIZE 100010 
using namespace std;
int n;
ll dp[SIZE];
int ar[SIZE];
ll solve(int i,int x)
{
	if(i>=n)
	{
		return 0;
	}
	if(dp[i]!=-1)
	{
		return dp[i];
	}
	dp[i]=max(ar[i]+solve(i+2,1),max(ar[i]+ar[i+1]+solve(i+4,2),ar[i]+ar[i+1]+ar[i+2]+solve(i+6,3)));
	return dp[i];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(ar,0,sizeof(ar));
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
		}
		memset(dp,-1,sizeof(dp));
		ll ans=solve(0,INT_MIN);
		cout<<dp[0]<<"\n";

	}
	return 0;
}