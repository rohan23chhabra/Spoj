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
int n;
int ar[1002];
int dp[1002][1002];
int solve(int i,int j)
{
	if(i>j)
	{
	    return 0;
	}
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	int v1,v2;
	if(ar[j]>ar[i+1])//taking ar[i]
	{
	    v1=ar[i]+solve(i+1,j-1);
	}
	else
	{
	    v1=ar[i]+solve(i+2,j);
	}
	
	if(ar[i]>=ar[j-1])//taking ar[j]
	{
	   v2=ar[j]+solve(i+1,j-1); 
	}
	else
	{
	    v2=ar[j]+solve(i,j-2);
	}
	return dp[i][j]=max(v1,v2);
}
int main()
{
	ios::sync_with_stdio(false);
	int gameno=0;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		gameno++;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
			sum+=ar[i];
		}
		memset(dp,-1,sz(dp));
		cout<<"In game "<<gameno<<", the greedy strategy might lose by as many as "<<2*solve(0,n-1)-sum<<" points.\n";
	}
	return 0;
}