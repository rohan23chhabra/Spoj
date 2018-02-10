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
int budget,n;
int fun[102],cost[102];
int dp[502][102];
int solve(int c,int i)
{
	if(c<0)
		return -100000;
	if(i==n)
		return 0;
	if(c==0)
		return 0;
	if(dp[c][i]!=-1)
		return dp[c][i];
	dp[c][i]=max(fun[i]+solve(c-cost[i],i+1),max(solve(c,i+1),solve(c-1,i)));
	return dp[c][i];
}
int main()
{
	ios::sync_with_stdio(false);
	while(1)
	{
		cin>>budget>>n;
		if((!budget) && (!n))
			break;
		for(int i=0;i<n;i++)
		{
			cin>>cost[i]>>fun[i];
		}
		memset(dp,-1,sz(dp));
		int ans=solve(budget,0),ans1;
		for(int i=1;i<=budget;i++)
		{
		    if(dp[i][0]==dp[budget][0])
		    {
		        ans1=i;
		        break;
		    }
		}
		cout<<ans1<<" "<<ans<<"\n";
	}
	return 0;
}