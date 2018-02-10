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
using namespace std;
long ar[10005];
long long dp[10005];
int n;
long long solve(int i)
{
	if(i>=n)
	{
		return 0;
	}
	if(dp[i]!=-1)
	{
		return dp[i];
	}
	dp[i]=max(ar[i]+solve(i+2),solve(i+1));
	return dp[i];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int x=1;x<=t;x++)
	{
		cin>>n;
		if(n==0)
		{
		    cout<<"Case "<<x<<": "<<0<<"\n";
		    continue;
		}
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
		}
		memset(dp,-1,sizeof(dp));
		long long ans=solve(0);
		cout<<"Case "<<x<<": "<<dp[0]<<"\n";
	}
	return 0;
}