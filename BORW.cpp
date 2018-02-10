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
#define init(a,v) memset(a,v,sizeof(a)) 
using namespace std;
typedef pair<int,int> ii;
typedef complex<double> point;
int dp[202][202][202];
int ar[202];
int n;
//int ans;
int solve(int current,int last1,int last2)
{
	if(current==n+1)
	{
		return 0;
	}
	int &a=dp[current][last1][last2];
	if(a!=-1)
	{
		return a;
	}
	a=INT_MIN;
	a=max(a,solve(current+1,last1,last2));
	if(last1==0 || ar[current]>ar[last1])
	{
		a=max(a,1+solve(current+1,current,last2));
	}
	if(last2==0 || ar[current]<ar[last2])
	{
		a=max(a,1+solve(current+1,last1,current));
	}
	return a;
}
int main()
{
	std::ios::sync_with_stdio(false);
	//int n;
	while(1)
	{
		cin>>n;
		if(n==-1)
			break;
		for(int i=1;i<=n;i++)
		{
			cin>>ar[i];
		}
		init(dp,-1);
		cout<<n-solve(1,0,0)<<"\n";
	}
	return 0;
}