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
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,times;
		ll tp[102][102];
		ll risk[102][102];
		//ll ans[102];
		ll dp[102][252];
		cin>>n>>times;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>tp[i][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>risk[i][j];	
		for(int i=0;i<102;i++)
		{
		    //ans[i]=INF;
			for(int j=0;j<252;j++)
				dp[i][j]=INF;
		}
		for(int i=0;i<=times;i++)
			dp[1][i]=0;
		//ans[1]=0;
		for(ll k=1;k<=times;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(j!=i)
					{
						if(k>=tp[i][j])
						{
							dp[j][k]=min(dp[j][k],risk[i][j]+dp[i][k-tp[i][j]]);
						}
						else
						{
							dp[j][k]=min(dp[j][k],dp[j][k-1]);
						}
					}
				}
			}
		}
		ll mintime=INF;
		for(int i=0;i<=times;i++)
		{
		    if(dp[n][i]==dp[n][times])
		    {
		        mintime=i;
		        break;
		    }
		}
		if(dp[n][times]!=INF)
		    cout<<dp[n][times]<<" "<<mintime<<"\n";
		else
		    cout<<"-1\n";
	}
	return 0;
}