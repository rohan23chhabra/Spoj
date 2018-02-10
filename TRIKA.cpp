#include <bits/stdc++.h>
#define mod 1000000007
#define mp make_pair
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define s(n) scanf("%d",&n)
#define trav(i,a,b) for(int i=a;i<b;i++) 
#define ll long long
using namespace std;

int main()
{
	int n,m,x,y,p[50][50],dp[50][50];
	s(n);
	s(m);
	s(x);
	s(y);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			s(p[i][j]);
		}
	}
	dp[x][y]=p[x][y];
	for(int i=x;i<=n;i++)
	{
		for(int j=y;j<=m;j++)
		{
			if(i-1>=x && j-1>=y)
			{
				int v1=dp[i-1][j]-p[i][j];
				int v2=dp[i][j-1]-p[i][j];
				dp[i][j]=max(v1,v2);
			}
			else if(i-1>=x)
			{
				dp[i][j]=dp[i-1][j]-p[i][j];
			}
			else if(j-1>=y)
			{
				dp[i][j]=dp[i][j-1]-p[i][j];
			}
		}
	}
	if(dp[n][m]>=0)
	{
		cout<<"Y "<<dp[n][m]<<"\n";
	}
	else
	{
		cout<<"N\n";
	}
	return 0;
}