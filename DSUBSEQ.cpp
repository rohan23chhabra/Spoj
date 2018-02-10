#include <bits/stdc++.h>
#define mod 1000000007
#define mp make_pair
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define i(n) scanf("%d",&n)
#define l(n) scanf("%ld",&n)
#define lld(n) scanf("%lld",&n)
#define ii(n,m) scanf("%d %d",&n,&m)
#define test int t;i(t);while(t--)
#define ll long long
#define LLINF LLONG_MAX
#define LINF LONG_MAX
#define INF INT_MAX
#define SIZE 100005 
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	i(t);
	while(t--)
	{
		string s;
		cin>>s;
		int pos[30];
		int dp[100005];
		dp[0]=1;
		memset(pos,-1,sizeof(pos));
		int n=s.size();
		for(int i=1;i<=n;i++)
		{
			dp[i]=(dp[i-1]*2)%mod;
			int c=s[i-1]-65;
			if(pos[c]!=-1)
			{
				dp[i]=(dp[i]-dp[pos[c]-1]+mod)%mod;
			}
			pos[c]=i;
		}
		cout<<dp[n]<<"\n";
	}
	return 0;
}