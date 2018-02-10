#include <bits/stdc++.h>
#define mod 1000000000
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
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	ll A=1,B=1,a[1002],b[1002];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		A=(A*a[i])%mod;
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
		B=(B*b[i])%mod;
	}
	ll hcf=gcd(A,B);
	int len=1+log10(hcf);
	while(len!=9)
	{
		cout<<0;
		len++;
	}
	cout<<hcf<<"\n";
	return 0;
}