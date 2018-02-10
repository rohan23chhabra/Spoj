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
const ll INF=1e9;
const long double eps=0.0000001;
int dp[250][250][30];
int solve(int prev,int cur,int i)
{
	if(i==n-1)
	{
		if(cur>=prev)
			return 1;
		return 0;
	}

}
int main()
{
	ios::sync_with_stdio(false);
	string ar;
	while(1)
	{
		cin>>ar;
		if(ar[0]=='b')
			break;
		mem(dp,-1);

	}
	return 0;
}