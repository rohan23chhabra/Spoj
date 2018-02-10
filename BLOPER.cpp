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
stack<pair<int,char> >ans;
int n,s;
int dp[501][2*125251];
bool symbol[501];
bool check(int n,int sum)
{
	if(dp[n][sum+125250]==1)
		return true;
	if(dp[n][sum+125250]==0)
		return false;
	if(sum==0)
	{
		dp[n][125250]=1;
		return true;
	}
	if(check(n-1,sum-n))
	{
		dp[n][sum+125250]=1;
		symbol[n]=true;
		return true;
	}
	if(check(n-1,sum+n))
	{
		dp[n][sum+125250]=1;
		symbol[n]=false;
		return true;
	}
	dp[n][sum+125250]=0;
	return false;
}
int main()
{
	
	cin>>n>>s;
	s--;
	if(check(n,s))
	{
		cout<<1;
		for(int i=2;i<=n;i++)
		{
			if(symbol[i])
				cout<<"+";
			else
				cout<<"-";
		}
	}
	else
	{
		cout<<"Impossible";
	}
	return 0;
}