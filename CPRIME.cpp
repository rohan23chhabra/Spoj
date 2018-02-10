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
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
const int mod=1000000007;
const ll INF=1e10;
vector<int>p;
int prime[1000*SIZE];
void sieve()
{
	mem(prime,0);
	prime[0]=prime[1]=1;
	for(int i=2;(ll)i*i<=1e8;i++)
	{
		if(!prime[i])
		{
			for(int j=i*i;j<=1e8;j+=i)
			{
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=1e8;i++)
	{
		if(!prime[i])
			p.pb(i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	sieve();
	int n;
	while(1)
	{
		cin>>n;
		if(!n)
			break;

	}
	return 0;
}