#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define maxn 100005
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define pi 3.141592653589793
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
typedef long long ll;
const int mod=1000000007;
const long double eps=1e-6;
ll power(ll a,ll n) {if(n==0){return 1;}ll p=power(a,n/2);p=p*p;if(n&1){p=p*a;}return p;}
ll gcd(ll a,ll b) {if(b){return gcd(b,a%b);}return a;}
vector<int> g[102],r[102];
int vis[102],ans;
stack<int> st;
void dfs1(int u)
{
	vis[u]=1;
	for(int i=0;i<g[u].size();i++)
	{
		if(!vis[g[u][i]])
			dfs1(g[u][i]);
	}
	st.push(u);
}
void dfs2(int u)
{
	vis[u]=1;
	for(int i=0;i<r[u].size();i++)
	{
		if(!vis[r[u][i]])
			dfs2(r[u][i]);
	}
}
void kosaraju()
{
	while(!st.empty())
	{
		int u = st.top();
		st.pop();
		if(!vis[u]) {
			dfs2(u);
			ans++;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	boost
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s[n];
		for(int i=0;i<n;i++)
			cin>>s[i];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(s[i][j]=='Y') {
					g[i].pb(j);
					r[j].pb(i);
				}
			}
		}
		
		for(int i=0;i<n;i++) {
			if(!vis[i]) {
				dfs1(i);
			}
		}

		mem(vis,0);
		kosaraju();

		mem(vis,0);
		ans=0;
		while(!st.empty())
			st.pop();
		for(int i=0;i<102;i++) {
			g[i].clear();
			r[i].clear();
		}
	}
	return 0;
}
