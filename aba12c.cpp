#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define ll long long
#define SIZE 100005
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define pi 3.141592653589793
#define nl cout<<"\n"
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
const int mod=1000000007;
const int N=1000000000;
const long double eps=1e-6;
ll dp[102][102];
int n,k,ar[102];
ll solve(int i,int j,int cnt)
{
	if(j==0)
	{
		if(cnt<=n)
			return 0;
		else
			return N;
	}
	if(j<0)
		return N;
	if(i==k+1)
		return N;
	if(dp[i][j]<N)
		return dp[i][j];
	if(ar[i]==-1)//packet not available
		dp[i][j]=min(dp[i][j],solve(i+1,j,cnt));
	else
	{
		//packet available
		dp[i][j]=min(dp[i][j],solve(i+1,j,cnt));//not taking
		dp[i][j]=min(dp[i][j],ar[i]+solve(i,j-i,cnt+1));//taking
	}
	return dp[i][j];
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=k;i++)
			cin>>ar[i];
		for(int i=0;i<102;i++)
			for(int j=0;j<102;j++)
				dp[i][j]=N;
		ll ans=solve(1,k,0);
		if(ans>=N)
			cout<<"-1\n";
		else
			cout<<ans<<"\n";
	}
	return 0;
}