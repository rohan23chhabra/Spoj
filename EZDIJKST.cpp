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
vector<ii>adj[10002];
ll dis[10002];
int vis[10002];
void dij(int source)
{
	for(int i=0;i<10002;i++)
	{
		dis[i]=LINF;
		vis[i]=0;
	}

	priority_queue<ii,vector<ii>,greater<ii> >q;
	q.push(mp(0,source));
	dis[source]=0;
	while(!q.empty())
	{
		ii tmp=q.top();
		int node=tmp.ss;
		int wt=tmp.ff;
		q.pop();
		if(vis[node])
			continue;
		vis[node]=1;
		for(int i=0;i<adj[node].size();i++)
		{
			int v=adj[node][i].ff;
			int weight=adj[node][i].ss;
			if(dis[v]>dis[node]+weight)
			{
				dis[v]=dis[node]+weight;
				q.push(mp(dis[v],v));
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int t,u,v,w,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<10002;i++)
		{
			adj[i].clear();
		}
		for(int i=0;i<m;i++)
		{
			cin>>u>>v>>w;
			adj[u].pb(mp(v,w));
		}
		int s,d;
		cin>>s>>d;
		dij(s);
		if(dis[d]!=LINF)
		{
			cout<<dis[d]<<"\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}