#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define ll long long
#define SIZE 100005
#define ff first
#define ss second
#define sz(a) sizeof(a) 
#define mem(a,b) memset(a,b,sizeof(a))
#define pi 3.141592653589793
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
const int mod=1000000007;
const ll INF=1e9;
const long double eps=1e-6;
int dp[15][100][100];
int main()
{
	ios::sync_with_stdio(false);
	dp[0][50][50]=1;
	for(int step=1;step<=14;step++)
	{
		for(int i=1;i<100;i++)
		{
			for(int j=1;j<100;j++)
			{
				dp[step][i][j]=dp[step-1][i-1][j]+dp[step-1][i][j-1]+dp[step-1][i+1][j-1]
				+dp[step-1][i+1][j]+dp[step-1][i][j+1]+dp[step-1][i-1][j+1];
			}
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<dp[n][50][50]<<"\n";
	}
	return 0;
}