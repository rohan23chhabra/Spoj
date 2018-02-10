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
vector<ii>adj1[502];
vector<ii>adj2[502];
int s,d;
long dis1[502];
long dis2[502];
int vis[502];
void dij1(int source)
{
	for(int i=0;i<502;i++)
	{
		dis1[i]=LINF;
		vis[i]=0;
	}

	priority_queue<ii,vector<ii>,greater<ii> >q;
	q.push(mp(0,source));
	dis1[source]=0;
	while(!q.empty())
	{
		ii tmp=q.top();
		int node=tmp.ss;
		int wt=tmp.ff;
		q.pop();
		if(vis[node])
			continue;
		vis[node]=1;
		for(int i=0;i<adj1[node].size();i++)
		{
			int v=adj1[node][i].ff;
			int weight=adj1[node][i].ss;
			if(dis1[v]>dis1[node]+weight)
			{
				dis1[v]=dis1[node]+weight;
				q.push(mp(dis1[v],v));
			}
		}
	}
}
void dij2(int source)
{
	for(int i=0;i<502;i++)
	{
		dis2[i]=LINF;
		vis[i]=0;
	}

	priority_queue<ii,vector<ii>,greater<ii> >q;
	q.push(mp(0,source));
	dis2[source]=0;
	while(!q.empty())
	{
		ii tmp=q.top();
		int node=tmp.ss;
		int wt=tmp.ff;
		q.pop();
		if(vis[node])
			continue;
		vis[node]=1;
		for(int i=0;i<adj2[node].size();i++)
		{
			int v=adj2[node][i].ff;
			int weight=adj2[node][i].ss;
			if(dis2[v]>dis2[node]+weight)
			{
				dis2[v]=dis2[node]+weight;
				q.push(mp(dis2[v],v));
			}
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n,m;
	while(1)
	{
		cin>>n>>m;
		if(n==0 && m==0)
		{
			break;
		}
		for(int i=0;i<n;i++)
		{
			adj1[i].clear();
			adj2[i].clear();
		}
		cin>>s>>d;
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			adj1[u].pb(mp(v,w));
			adj2[v].pb(mp(u,w));
		}
		dij1(s);
		dij2(d);
		for(int u=0;u<n;u++)
		{
			vector<ii>::iterator it;
			for(it=adj1[u].begin();it!=adj1[u].end();it++)
			{
				int v=(*it).ff;
				int w=(*it).ss;
				if(dis1[u]+dis2[v]+w==dis1[d])
				{
					adj1[u].erase(it);
				}
			}
		}
		dij1(s);
		if(dis1[d]!=LINF)
		{
			cout<<dis1[d]<<"\n";
		}
		else
		{
			cout<<"-1\n";
		}
	}
	return 0;
}