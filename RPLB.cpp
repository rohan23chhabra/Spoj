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
int n,ar[SIZE],k,dp[1002][1002];
int solve(int i,int cur_ans)
{
	if(i>=n)
		return cur_ans;
	if(dp[i][w]!=-1)
		return dp[i][cur_ans];
	if(ar[i]+cur_ans<=k)
		dp[i][cur_ans]=ar[i]+solve(i+2,ar[i]+cur_ans)
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int x=1;x<=t;x++)
	{
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>ar[i];
		memset(dp,-1,sz(dp));

	}
	return 0;
}