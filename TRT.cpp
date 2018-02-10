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
int v[2002];
ll dp[2002][2002];
int n;
ll solve(int i,int j,int a)
{
	if(i==j)
		return a*v[i];
	if(dp[i][j]!=-1)
		return dp[i][j];
	dp[i][j]=max(a*v[i]+solve(i+1,j,a+1),a*v[j]+solve(i,j-1,a+1));
	return dp[i][j];
}
int main()
{
	ios::sync_with_stdio(false);
	//int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i];
	memset(dp,-1,sz(dp));
	cout<<solve(0,n-1,1)<<"\n";
	return 0;
}