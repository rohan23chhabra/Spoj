#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define ll long long
#define SIZE 1e5
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
const int mod=1e9+7;
const ll INF=1e10;
int y[502][502],b[502][502],py[502][502],pb[502][502];
int dp[502][502];
int solve(int i,int j)
{
	if(i==0 || j==0)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];

	//taking y[i][j]
	dp[i][j]=py[i][j]-py[i][0]+solve(i-1,j);
	dp[i][j]=max(dp[i][j],pb[i][j]-pb[0][j]+solve(i,j-1));
	return dp[i][j];
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(1)
	{
		cin>>n>>m;
		if(!n)
			break;

		for(int i=1;i<=n;i++)
		{
			py[i][0]=0;
			for(int j=1;j<=m;j++)
			{
				cin>>y[i][j];
				py[i][j]=y[i][j]+py[i][j-1];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				pb[0][j]=0;
				cin>>b[i][j];
				pb[i][j]=b[i][j]+pb[i-1][j];
			}
		}	
		mem(dp,-1);
		cout<<solve(n,m)<<"\n";
	}
	return 0;
}