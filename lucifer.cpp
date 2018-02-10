#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define maxn 100005
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define pi 3.141592653589793
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
typedef long long ll;
const int mod=1000000007;
ll dp[20][100][100][2];
int prime[maxn];
void sieve()
{
	mem(prime,0);
	prime[0]=prime[1]=1;
	for(int i=2;i*i<maxn;i++)
	{
		if(!prime[i])
		{
			for(int j=i*i;j<maxn;j+=i)
				prime[j]=1;
		}
	}
}
ll solve(string &s,int idx,int even,int odd,int smaller)
{
	int len=s.length();
	if(idx==len)
	{
		if(even>=odd)
			return 1LL-prime[even-odd];
		return 0LL;
	}
	ll &ans=dp[idx][even][odd][smaller];
	if(ans!=-1 && smaller!=1)
		return ans;
	ll ret=0;
	int lim=9;
	if(smaller)
		lim=s[idx]-'0';
	for(int d=0;d<=lim;d++)
	{
		int ns=smaller;
		if(d<s[idx]-'0')
			ns=0;
		if((len-idx)%2==0)//even
			ret+=solve(s,idx+1,even+d,odd,ns);
		else
			ret+=solve(s,idx+1,even,odd+d,ns);
	}
	if(smaller==0)
		return dp[idx][even][odd][smaller]=ret;
	return ret;
}
int main()
{
	int t;
	cin>>t;
	sieve();
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		char A[25],B[25];
		sprintf(A,"%lld",a-1);
		sprintf(B,"%lld",b);
		string s1(A);
		string s2(B);
		mem(dp,-1);
		ll ans1=solve(s1,0,0,0,1);
		mem(dp,-1);
		ll ans2=solve(s2,0,0,0,1);
		if(a)
			cout<<ans2-ans1<<"\n";
		else
			cout<<ans2<<"\n";
	}
}