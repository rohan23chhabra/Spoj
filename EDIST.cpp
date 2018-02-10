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
#define s(a) sizeof(a) 
using namespace std;
typedef pair<int,int> ii;

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		int dp[2002][2002];
		cin>>a>>b;
		int n=a.size();
		int m=b.size();
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=n;i++)
		{
			dp[0][i]=i;
		}
		for(int j=0;j<=m;j++)
		{
			dp[j][0]=j;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i-1]==b[j-1])
				{
					dp[i][j]=dp[i-1][j-1];
				}
				else
				{
					dp[i][j]=min(1+dp[i-1][j-1],min(1+dp[i-1][j],1+dp[i][j-1]));
				}
			}
		}
		cout<<dp[n][m]<<"\n";
	}
	return 0;
}