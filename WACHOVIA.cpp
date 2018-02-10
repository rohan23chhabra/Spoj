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
#define s(a) sizeof(a) 
using namespace std;
typedef pair<int,int> ii;
typedef complex<double> point;
int weight[SIZE];
int v[SIZE];
int m,k;
int dp[1002][1002];
int solve(int i,int w)
{
	if(i<0)
		return 0;
	if(dp[i][w]!=-1)
		return dp[i][w];
	dp[i][w]=solve(i-1,w);
	if(weight[i]<=w)
		dp[i][w]=max(dp[i][w],v[i]+solve(i-1,w-weight[i]));
	return dp[i][w];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>k>>m;
		for(int i=0;i<m;i++)
		{
			cin>>weight[i]>>v[i];
		}
		memset(dp,-1,s(dp));
		cout<<"Hey stupid robber, you can get "<<solve(m-1,k)<<".\n";
	}
	return 0;
}