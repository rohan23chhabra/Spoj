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
typedef pair<int,int> ii;
void multiply(ll F[2][2],ll M[2][2])
{
	ll x =  ((F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod)%mod;
	ll y =  ((F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod)%mod;
	ll z =  ((F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod)%mod;
	ll w =  ((F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod)%mod;
	 
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}
void power(ll F[2][2],ll n)
{
	if(n==0 || n==1)
		return;
	ll M[2][2]={{1,1},{1,0}};
	power(F,n/2);
	multiply(F,F);
	if(n&1)
		multiply(F,M);
}
ll fib(ll n)
{
	ll F[2][2]={{1,1},{1,0}};
	if(n==0)
		return 0;
	power(F,n-1);
	return F[0][0];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		cout<<(fib(m+2)-fib(n+1)+mod)%mod<<"\n";
	}
	return 0;
}