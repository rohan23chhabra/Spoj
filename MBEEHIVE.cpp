#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define ll long long
#define SIZE 100005
#define ff first
#define ss second
#define sz(a) sizeof(a) 
#define mem(a,b) memset(a,b,sizeof(a))
#define pi 3.141592653589793
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
const int mod=1000000007;
const ll INF=1e9;
const long double eps=1e-6;
int n;
int solve(int i,int j,int step)
{
	if(n==1)
		return 0;
	if(step==n)
	{
		if(i==0 && j==0)
			return 1;
		return 0;
	}
	int n1=solve(i-1,j,step+1);
	int n2=solve(i,j-1,step+1);
	int n3=solve(i+1,j-1,step+1);
	int n4=solve(i+1,j,step+1);
	int n5=solve(i,j+1,step+1);
	int n6=solve(i-1,j+1,step+1);
	return n1+n2+n3+n4+n5+n6;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<solve(0,0,0)<<endl;
	}
	return 0;
}