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
map<int,ll>dp;
ll max(ll a,ll b)
{
	if(a>=b)
		return a;
	else
		return b;
}
ll solve(int n)
{
	if(n==0 || n==1)
		return n;
	if(dp[n]!=0)
	{
		return dp[n];
	}
	dp[n]=max(n,solve(n/2)+solve(n/3)+solve(n/4));
	return dp[n];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	while(scanf("%d",&n)==1)
	{
		dp.clear();
		cout<<solve(n)<<"\n";
	}
	return 0;
}