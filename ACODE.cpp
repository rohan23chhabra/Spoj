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

int main()
{
	std::ios::sync_with_stdio(false);
	char ar[5005];
	ll dp[5005];
	while(1)
	{
		cin>>ar;
		if(strcmp(ar,"0")==0)
		{
			break;
		}
		int n=strlen(ar);
		if(n==1)
		{
			cout<<"1\n";
			continue;
		}
		dp[0]=1;
		if((ar[0]=='1' && ar[1]!='0') || (ar[0]=='2' && (ar[1]>='1' && ar[1]<='6')))
		{
			dp[1]=2;
		}
		else if(ar[1]=='0' && (ar[0]>='3' && ar[0]<='9'))
		{
			dp[1]=0;
		}
		else
		{
			dp[1]=1;
		}
		for(int i=2;i<n;i++)
		{
			if((ar[i-1]=='1' && ar[i]!='0') || (ar[i-1]=='2' && (ar[i]>='1' && ar[i]<='6')))
			{
				dp[i]=dp[i-1]+dp[i-2];
			}
			else if(ar[i]=='0' && ar[i-1]=='0')
			{
				dp[i]=0;
			}
			else if(ar[i]=='0')
			{
				dp[i]=dp[i-2];
			}
			else
			{
				dp[i]=dp[i-1];
			}
		}
		cout<<dp[n-1]<<"\n";
	}
	return 0;
}