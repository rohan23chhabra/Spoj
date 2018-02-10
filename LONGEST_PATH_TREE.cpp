#include <bits/stdc++.h>
using namespace std;
vector<int>adj[100000];
void bfs(int s);
int dis[100000];
int vis[100000];
int m1;
int node;
queue<int>q;
void clear(queue<int>&q);
int main()
{
	int n,u,v;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	m1=0;
	node=1;
	bfs(1);
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	clear(q);
	m1=0;
	bfs(node);
	cout<<m1<<"\n";
	return 0;
}
void bfs(int s)
{
	dis[s]=0;
	vis[s]=1;
	q.push(s);
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
				dis[v]=dis[u]+1;
				if(dis[v]>m1)
				{
					m1=dis[v];
					node=v;
				}
				q.push(v);
			}
		}
	}
}
void clear(queue<int>&q)
{
	queue<int>empty;
	swap(q,empty);
}