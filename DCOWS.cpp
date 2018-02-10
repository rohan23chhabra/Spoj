#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define ll long long
#define SIZE 100005
#define ff first
#define ss second
#define X real()
#define Y imag()
#define sz(a) sizeof(a) 
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
typedef complex<double> point;
const int mod=1000000007;
const ll INF=1e10;
int n,m;
int b[5002],c[5002];
ll dp[5002][5002];
ll solve(int i,int j)
{
    if(i>j)
        return dp[i][j]=INF;
	if(i==0)
	    return dp[i][j]=0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	return dp[i][j]=min(abs(b[i]-c[j])+solve(i-1,j-1),solve(i,j-1));
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int j=1;j<=n;j++)
		cin>>c[j];
	sort(b+1,b+m+1);
	sort(c+1,c+n+1);
	mem(dp,-1);
	cout<<solve(m,n)<<"\n";
	return 0;
}