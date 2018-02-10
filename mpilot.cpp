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
using namespace std;
typedef pair<int,int> ii;
typedef complex<double> point;
const int mod=1000000007;
const ll INF=1e10;
int n,ca[10002],as[10002];
ll dp[5002][5002];
ll solve(int i,int j)
{
	if(i==1 && j==0)
		return as[1];
	if((i-j)<j)
		return INF;
	if(dp[i][j]!=-1)
		return dp[i][j];
	return dp[i][j]=min(solve(i-1,j-1)+ca[i],solve(i-1,j)+as[i]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ca[i]>>as[i];
	}
	for(int i=0;i<5002;i++)
	{
		for(int j=0;j<5002;j++)
			dp[i][j]=INF;
	}
	//memset(mark,0,sz(mark));
	cout<<ca[n]+solve(n-1,(n/2)-1)<<"\n";
	return 0;
}