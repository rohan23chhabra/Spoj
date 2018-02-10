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

void bfs(int s,int dist[],vector<int>(&adj)[SIZE],int vis[])
{
	memset(dist,INF,sz(dist));
	memset(vis,0,sz(vis));
	queue<int>q;
	q.push(s);
	dist[s]=0;
	vis[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i];
			if(vis[v]==0)
			{
				vis[v]=1;
				dist[v]=1+dist[u];
				q.push(v);
			}
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<int>rail[SIZE];
		vector<int>road[SIZE];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				road[i].pb(j);
			}
		}
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			rail[u].pb(v);
			vector<int>::iterator it=find(all(road[u]),v);
			road[u].erase(it);
		}
		int dist1[SIZE],dist2[SIZE];
		int vis[SIZE];
		bfs(1,dist1,rail,vis);
		bfs(1,dist2,road,vis);
		if(dist1[n]==INF || dist2[n]==INF)
			cout<<-1;
		else
			cout<<max(dist1[n],dist2[n]);
	}
	return 0;
}