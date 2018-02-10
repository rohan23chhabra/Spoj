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
int main()
{
	ios::sync_with_stdio(false);
	ll dp[15][1000];
	memset(dp,0,sz(dp));
	dp[1][0]=1;
	dp[1][1]=0;
	dp[2][0]=1;
	dp[2][1]=1;
	for(int i=3;i<=12;i++)
	{
		int m=(i-1)*(i-2)/2;
		for(int j=0;j<99;j++)
		{
			for(int x=0;x<=m;x++)
			{
				if(j-x>=0 && j-x<i)
				{
					dp[i][j]+=dp[i-1][x];
				}
			}
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<dp[n][k]<<"\n";
	}
	return 0;
}