#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define maxn 1005
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define pi 3.141592653589793
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
typedef long long ll;
const int mod=1000000007;
const ll INF=1e9;
const long double eps=1e-6;
ll power(ll a,ll n) {if(n==0){return 1;}ll p=power(a,n/2);p=p*p;if(n&1){p=p*a;}return p;}
ll gcd(ll a,ll b){if(b){return gcd(b,a%b);}return a;}

vector<int>g[maxn];
int L[maxn];

void dfs(int u,int T[maxn],int p)
{
	T[u]=p;
	if(p==-1)
		L[u]=0;
	else
		L[u]=1+L[p];
	for(int i=0;i<g[u].size();i++)
	{
		if(g[u][i]!=p)
			dfs(g[u][i],T,u);
	}
}
void preprocess(int n,int T[maxn],int P[maxn][20])
{
	for(int i=1;i<=n;i++)
		for(int j=0;(1<<j)<=n;j++)
			P[i][j]=-1;

	for(int i=1;i<=n;i++)
		P[i][0]=T[i];

	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i<=n;i++)
			if(P[i][j-1]!=-1)
				P[i][j]=P[P[i][j-1]][j-1];

}
int lca(int p,int q,int T[maxn],int P[maxn][20])
{
	int log;
	if(L[p] < L[q])
		swap(p,q);
	for(log=0;(1<<log)<=L[p];log++);
	log--;
	for(int i=log;i>=0;i--)
		if(L[p] - (1<<i) >=L[q])
			p=P[p][i];

	if(p==q)
		return p;

	for(int i=log;i>=0;i--)
		if(P[p][i]!=-1 && P[p][i]!=P[q][i])
			p=P[p][i],q=P[q][i];

	return T[p];
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		int n,m,T[maxn],P[maxn][20];
		for(int i=0;i<maxn;i++)
		{
			for(int j=0;j<20;j++)
				P[i][j]=0;
			T[i]=0;
			g[i].clear();
			L[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int m,num;
			cin>>m;
			for(int j=1;j<=m;j++)
			{
				cin>>num;
				g[i].pb(num);
				g[num].pb(i);
			}
		}
		//creating parent array T and level array L.
		dfs(1,T,-1);
		preprocess(n,T,P);
		cin>>m;
		cout<<"Case "<<c<<":\n";
		while(m--)
		{
			int u,v;
			cin>>u>>v;
			int ans=lca(u,v,T,P);
			cout<< ((ans==-1) ? 1 : ans) <<"\n";
		}
	}
	return 0;
}
