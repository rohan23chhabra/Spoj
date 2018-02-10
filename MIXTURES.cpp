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
#define s(a) sizeof(a)  
using namespace std;
int ar[]
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
		}
		memset(dp,-1,s(dp));
		cout<<solve(0)<<"\n";
	}
	return 0;
}