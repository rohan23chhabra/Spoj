#include <bits/stdc++.h>
#define mod 1000000007
#define mp make_pair
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define i(n) scanf("%d",&n)
#define l(n) scanf("%ld",&n)
#define lld(n) scanf("%lld",&n)
#define ii(n,m) scanf("%d %d",&n,&m)
#define trav(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define LLINF LLONG_MAX
#define LINF LONG_MAX
#define INF INT_MAX
#define SIZE 100005 
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	while(1)
	{
		int n,T;
		ii(n,T);
		if(!n && !T)
			break;
		int toll[55][55];
		int time[55][55];
		trav(i,1,n+1)
		{
			trav(j,1,1+n)
			{
				i(time[i][j]);
			}
		}
		trav(i,1,1+n)
		{
			trav(j,1,1+n)
			{
				i(toll[i][j]);
			}
		}
		ll dp[1005][55];
		trav(i,0,1005)
		{
			trav(j,0,55)
			{
				dp[i][j]=LINF;
			}
		}
		dp[0][1]=0;
		int tt=INF;
		//int best=INF;
		trav(t,1,T)
		{
			trav(i,1,n+1)
			{
				trav(j,1,n+1)
				{
					if(i!=j)
					{
						if(t>=time[i][j])
						dp[t][j]=min(min(dp[t-1][j],dp[t][j]),toll[i][j]+dp[t-time[i][j]][i]);
					}
				}
			}
			if(dp[t][n]!=dp[t-1][n])
			{
				tt=t;
			}
		}
		cout<<dp[T][n]<<" "<<tt<<"\n";
	}
	return 0;
}