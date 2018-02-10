#include <bits/stdc++.h>
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
const int mod=1000000007;
ll dp[502][10000];
int e,f,W,n,p[502],wt[502];
ll solve(int i,int w)
{
	if(w<0)
		return INF;
	
	if(w==0)
		return 0;

	if(i==n)
		return INF;
	
	if(dp[i][w]!=-1)
		return dp[i][w];

	dp[i][w]=min(solve(i+1,w),p[i]+solve(i,w-wt[i]));
	return dp[i][w];
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>e>>f;
		W=f-e;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>p[i]>>wt[i];
		}
		memset(dp,-1,sz(dp));
		ll ans=solve(0,W);
		if(ans>=INF)
		{
			cout<<"This is impossible.\n";
		}
		else
		{
			cout<<"The minimum amount of money in the piggy-bank is "<<ans<<".\n";
		}
	}
	return 0;
}