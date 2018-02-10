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
int dp[25][1002][2];
int cost[25][25];
int rating[25][25];
int open[25];
int n,m,K;
int solve(int bno,int k,int isOpen)
{
	if(bno==n)
		return 0;
	int &ans=dp[bno][k][isOpen];
	if(ans!=-1)
		return ans;
	ans=solve(bno+1,k,0);
	if(open[bno]<=k && isOpen==0)
	{
		k-=open[bno];
		for(int i=0;i<m;i++)
		{
			if(k>=cost[bno][i])
			ans=max(ans,rating[bno][i]+solve(bno,k-cost[bno][i],1));
		}
		k+=open[bno];
	}
	if(isOpen)
	{
		for(int i=0;i<m;i++)
		{
			if(k>=cost[bno][i])
				ans=max(ans,rating[bno][i]+solve(bno,k-cost[bno][i],1));
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>K;
		for(int i=0;i<n;i++)
			cin>>open[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>cost[i][j];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>rating[i][j];
		}
		memset(dp,-1,sz(dp));
		cout<<solve(0,K,0)<<"\n";
	}
	return 0;
}