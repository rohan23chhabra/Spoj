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
long long dp[10005][105];
vector<pair<int,pair<int,int> > >adj[105];
void bfs1(int s)
{
	int vis[105];
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i].first;
			int toll=adj[u][i].second.second;
			int len=adj[u][i].second.first;
			if(vis[v]==0)
			{
				vis[v]=1;
				if(toll==0)
				dp[0][v]=len+dp[0][u];
				q.push(v);
			}
			else
			{
				if(toll==0)
				dp[0][v]=min(len+dp[0][u],dp[0][v]);
			}
		}
	}
}
void bfs2(int s,int k)
{
	int vis[105];
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i].first;
			int toll=adj[u][i].second.second;
			int len=adj[u][i].second.first;
			if(vis[v]==0)
			{
				vis[v]=1;
				if(k>=toll)
					dp[k][v]=min(len+dp[k-toll][u],dp[k-1][v]);
				else
					dp[k][v]=dp[k-1][v];
				q.push(v);
			}
			else
			{
				if(k>=toll)
				dp[k][v]=min(dp[k][v],len+dp[k-toll][u]);
			}
		}
	}
}
int main()
{
	int test,k,r,n,u,v,l,t;
	s(test);
	while(test--)
	{
		s(k);s(n);s(r);
		for(int i=0;i<=105;i++)
		{
		    adj[i].clear();
		}
		for(int i=0;i<r;i++)
		{
			s(u);s(v);s(l);s(t);
			adj[u].pb(mp(v,mp(l,t)));
		}
		for(int i=0;i<=10000;i++)
		{
			for(int j=0;j<=100;j++)
			{
				dp[i][j]=LONG_MAX;
			}
		}
		dp[0][1]=0;
		bfs1(1);//handling the case for 0 toll.
		for(int K=1;K<=k;K++)
		{
			dp[K][1]=0;
			bfs2(1,K);
		}
		if(dp[k][n]>=LONG_MAX)
		{
		    cout<<"-1\n";
		}
		else
		{
		    cout<<dp[k][n]<<endl;
		}
	} 
	return 0;
}