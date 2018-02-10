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
#define s(a) sizeof(a) 
using namespace std;
typedef pair<int,int> ii;
typedef complex<double> point;
vector<int>adj[21];
ll dp[1048578];
int n;
ll solve(int mask,int ano)
{
	if(ano==n)
	{
		if(mask==(1<<n)-1)
		{
			return 1;
		}
		return 0;
	}
	if(dp[mask]!=-1)
		return dp[mask];
	dp[mask]=0;
	for(int j=0;j<adj[ano].size();j++)
	{
		int student=adj[ano][j];
		if((mask&(1<<student))==0)
			dp[mask]+=solve(mask|1<<student,ano+1);
	}
	return dp[mask];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int t; 
	cin>>t;
	while(t--)
	{
		int k;
		cin>>n;
		for(int i=0;i<21;i++)
			adj[i].clear();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>k;
				if(k)
					adj[j].pb(i);
			}
		}
		memset(dp,-1,s(dp));
		cout<<solve(0,0)<<"\n";
	}
	return 0;
}