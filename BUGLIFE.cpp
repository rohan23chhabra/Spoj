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
using namespace std;
vector<int>adj[2005];
int color[2005];
int bfs(int s)
{
	color[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i];
			if(color[v]==-1)
			{
				color[v]=3-color[u];
				q.push(v);
			}
			else if(color[v]==color[u])
			{
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int t,u,v,n,m;
	cin>>t;
	for(int x=1;x<=t;x++)
	{
		for(int i=0;i<2005;i++)
		{
			adj[i].clear();
		}
		memset(color,-1,sizeof(color));
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(color[i]==-1)
			{
				if(bfs(i)==0)
				{
					flag=1;
					break;
				}
			}
		}
		cout<<"Scenario #"<<x<<":\n";
		if(flag)
		{
			cout<<"Suspicious bugs found!\n";
		}
		else
		{
			cout<<"No suspicious bugs found!\n";
		}
	}
	return 0;
}