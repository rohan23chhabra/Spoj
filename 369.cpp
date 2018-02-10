#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int mod=1000000007;
ll dp[55][52][52][2];
ll F(string &s,int idx,int b,int c,int flag)
{
	//b = six - three
	//c = nine - three
	int len=s.length();
	if(idx==len)
	{
		if(flag && !b && !c)//flag=1 when any of the threes is used
			return 1;
		return 0;
	}
	ll &ret=dp[idx][b][c][flag];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int d=0;d<10;d++)
	{
		if(d==3)
			ret+=F(s,idx+1,b-1,c-1,1);
		else if(d==6)
			ret+=F(s,idx+1,b+1,c,flag);
		else if(d==9)
			ret+=F(s,idx+1,b,c+1,flag);
		else
			ret+=F(s,idx+1,b,c,flag);
		ret%=mod;
	}
	return ret;
}
ll solve(string &s)
{
	ll ans=0;
	int idx=0;
	int b=0,c=0,flag=0;
	for(int i=0;i<s.length();i++)
	{
		int d=s[i]-'0';
		for(int j=0;j<d;j++)
		{
			if(j==3)
				ans+=F(s,idx+1,b-1,c-1,1);
			else if(j==6)
				ans+=F(s,idx+1,b+1,c,flag);
			else if(j==9)
				ans+=F(s,idx+1,b,c+1,flag);
			else
				ans+=F(s,idx+1,b,c,flag);
			ans%=mod;
		}
		if(d==3)
		{
			b--;
			c--;
			flag=1;
		}
		else if(d==6)
			b++;
		else if(d==9)
			c++;
		idx++;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		mem(dp,-1);
		ll ans1=solve(a);
		mem(dp,-1);
		ll ans2=solve(b);
		ll ans=(ans2-ans1+mod)%mod;
		int three=0,six=0,nine=0;
		for(int i=0;i<a.length();i++)
		{
			if(a[i]=='3')
				three++;
			if(a[i]=='6')
				six++;
			if(a[i]=='9')
				nine++;
		}
		if(three && (three==six) && (three==nine))
			ans=(ans+1)%mod;
		cout<<ans<<"\n";
	}
	return 0;
}
