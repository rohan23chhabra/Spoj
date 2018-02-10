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
int ar[11];
int n;
int solve(int current,int last)
{
	if(current==n)
	{
		return 0;
	}
	int ans=0;
	ans=max(ans,solve(current+1,last));
	if(ar[current]>ar[last])
	{
		ans=max(ans,1+solve(current+1,current));
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<solve(0,-1);

	return 0;
}