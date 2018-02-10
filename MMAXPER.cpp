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
int n;
int dp[1002][2];
int a[1002],b[1002];
int solve(int i,int orient)
{
	if(dp[i][orient]!=-1)
		return dp[i][orient];
	if(orient==0)
	{
		if(i>0)
			dp[i][0]=max(a[i]+abs(b[i]-b[i-1])+solve(i-1,0),a[i]+abs(b[i]-a[i-1])+solve(i-1,1));
		else
			dp[i][0]=a[i];
	}
	if(orient==1)
	{
		if(i>0)
			dp[i][1]=max(b[i]+abs(a[i]-b[i-1])+solve(i-1,0),b[i]+abs(a[i]-a[i-1])+solve(i-1,1));
		else
			dp[i][1]=b[i];
	}
	return dp[i][orient];
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i];
	mem(dp,-1);
	cout<<max(solve(n-1,0),solve(n-1,1))<<"\n";
	return 0;
}