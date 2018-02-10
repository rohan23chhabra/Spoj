#include <bits/stdc++.h>
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
const int mod=1000000007;
int n;
string a;
int prefix[SIZE];
ll ans;
ll dp[202][202];
ll solve(int i,int j)
{
	if(i>j)
		return 0;

	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
		
	int ones;
	if(i>0)
		ones=prefix[j]-prefix[i-1];
	else if(i==0)
		ones=prefix[j];

	int zero=j-i+1-ones;
	if(ones>zero)
	{
		return j-i+1;
	}
	int m=0;
	for(int x=i+1;x<=j;x++)
	{
		int left=solve(i,x-1);
		int right=solve(x,j);
		if(left+right>m)
		{
			m=left+right;
		}
	}
	return dp[i][j]=m;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>a;
		int d=a[0]-'0';
		if(d)
			prefix[0]=1;
		else
			prefix[0]=0;

		for(int i=1;i<n;i++)
		{
			d=a[i]-'0';
			if(d)
			{
				prefix[i]=1+prefix[i-1];
			}
			else
			{
				prefix[i]=prefix[i-1];
			}
		}
		/*for(int i=0;i<n;i++)
			cout<<prefix[i]<<" ";
		cout<<endl;*/
		memset(dp,-1,sz(dp));
		cout<<solve(0,n-1)<<"\n";
	}
	return 0;
}