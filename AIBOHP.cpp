#include <bits/stdc++.h>
#define s(n) scanf("%d",&n)
using namespace std;
int dp[5001][5001];
char s[5001];
int ans(int l,int r)
{
	if(l<0 || r<0)
	{
		return 10000;
	}
	if(dp[l][r]!=-1)
	{
		return dp[l][r];
	}
	if(l>r)
	{
		return (dp[l][r]=10000);
	}
	if(l==r)
	{
		return (dp[l][r]=0);
	}
	if(s[l]==s[r])
	{
	    if(r==l+1)
	    {
	        return (dp[l][r]=0);   
	    }
	    else
	    {
		    return (dp[l][r]=ans(l+1,r-1));
	    }
	}
	else
	{
		dp[l][r]=min(1+ans(l+1,r),1+ans(l,r-1));
		return dp[l][r];
	}
}
int main()
{
	int n;
	s(n);
	//while(t--)
		memset(dp,-1,sizeof(dp));
		scanf("%s",s);
		//int n=s.size();
		//cout<<n<<endl;
		int a=ans(0,n-1);
		printf("%d\n",a);
	return 0;
}