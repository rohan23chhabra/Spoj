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
	vector<int>adj[SIZE];
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	set<int>vis;
	int ans=0;
	priority_queue<ii>s;
	int ver=1;
	int siz=adj[1].size();
	for(int i=2;i<=n;i++)
	{
		if(adj[i].size()>siz)
		{
			siz=adj[i].size();
			ver=i;
		}
	}
	s.push(mp(siz,ver));
	while(!s.empty())
	{
		ii p=s.top();
		s.pop();
		int u=p.ss;
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i];
			vis.insert(v);
			vector<int>::iterator v_it=find(all(adj[u]),v);
			adj[u].erase(v_it);
			v_it=find(all(adj[v]),u);
			adj[v].erase(v_it);
			cout<<adj[v].size()<<" "<<v<<endl;
			s.push(mp(adj[v].size(),v));
		}
		vis.insert(u);
		if(adj[u].size()>0)
		ans++;
		if(vis.size()==n)
			break;
	}
	cout<<ans;
	return 0;
}