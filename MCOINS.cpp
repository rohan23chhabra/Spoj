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
int dp[1000002];
int main()
{
	ios::sync_with_stdio(false);
	int k,l,m;
	cin>>k>>l>>m;
	memset(dp,-1,sz(dp));
	dp[1]=dp[k]=dp[l]=1;
	for(int i=2;i<=1000000;i++)
	{
	    if(dp[i]==-1)
	    {
	        if(i>l)
	        {
	            if(dp[i-1]==2 || dp[i-k]==2 || dp[i-l]==2)
	                dp[i]=1;
	            else
	                dp[i]=2;
	        }
	        else if(i>k)
	        {
	            if(dp[i-1]==2 || dp[i-k]==2)
	                dp[i]=1;
	            else
	                dp[i]=2;
	        }
	        else
	        {
	            if(dp[i-1]==2)
	                dp[i]=1;
	            else
	                dp[i]=2;
	        }
	    }
	}
	while(m--)
	{
		int n;
		cin>>n;
		if(dp[n]==1)
		    cout<<'A';
		else
		    cout<<'B';
	}
	return 0;
}