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
using namespace std;
ll dp[5][1002][1002];
int solve(int h,int a,int state)
{
	if(h<=0 || a<=0)
	{
		return 0;
	}
	if(dp[state][h][a]!=-1)
	{
		return dp[state][h][a];
	}
	if(state==0)//presently in air, can go to either water or fire 
	{
		dp[state][h][a]=max(1+solve(h-5,a-10,1),1+solve(h-20,a+5,2));
	}
	if(state==1)//presently in water, can go to either air or fire
	{
		dp[state][h][a]=max(1+solve(h+3,a+2,0),1+solve(h-20,a+5,2));
	} 
	if(state==2)//presently in fire, can go to either air or water
	{
		dp[state][h][a]=max(1+solve(h+3,a+2,0),1+solve(h-5,a-10,1));
	}
	return dp[state][h][a];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int t,h,a;
	cin>>t;
	while(t--)
	{
		cin>>h>>a;
		ll ans=0;
		for(int i=0;i<3;i++)
		{
			memset(dp,-1,sizeof(dp));
			int s=solve(h,a,i);
			ans=max(ans,dp[i][h][a]);
		}
		if(ans!=0)
			cout<<ans-1<<"\n";
		else
			cout<<"0\n";
	}
	return 0;
}