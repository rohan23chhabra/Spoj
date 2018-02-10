#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define ll long long
#define SIZE 100005
#define ff first
#define ss second
#define sz(a) sizeof(a) 
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
const int mod=1000000007;
const ll INF=1e10;
int m,n;
string ar[202];
int dp[202][202][2];
bool isSafe(int i,int j)
{
	if(i<0 || j<0 || i==m || j==n || ar[i][j]=='#')
		return false;
	return true;
}
int solve(int i,int j,int f)
{
	if(j==0 && i==m-1 && f==0)
	{
		if(ar[i][j]=='T')
			return 1;
		else 
			return 0;
	}
	if(j==n-1 && i==m-1 && f==1)
	{
		if(ar[i][j]=='T')
			return 1;
		else 
			return 0;
	}
	if(dp[i][j][f]!=-1)
		return dp[i][j][f];
	
	if(isSafe(i,j))
	{
		if(f==0)//left
		{
			int v;
			if(ar[i][j]=='T')
				v=1;
			else
				v=0;
			dp[i][j][f]=max(v+solve(i,j-1,f),v+solve(i+1,j,1-f));
		}
		else//right
		{
			int v;
			if(ar[i][j]=='T')
				v=1;
			else
				v=0;
			dp[i][j][f]=max(v+solve(i,j+1,f),v+solve(i+1,j,1-f));
		}
		return dp[i][j][f];
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		for(int i=0;i<m;i++)
		{
			cin>>ar[i];
		}
		mem(dp,-1);
		cout<<solve(0,0,1)<<"\n";
	}
	return 0;
}