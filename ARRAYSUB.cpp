#include <bits/stdc++.h>
#define mod 1000000007
#define mp make_pair
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define i(n) scanf("%d",&n)
#define l(n) scanf("%ld",&n)
#define lld(n) scanf("%lld",&n)
#define ii(n,m) scanf("%d %d",&n,&m)
#define trav(i,a,b) for(int i=a;i<b;i++)
#define test int t;i(t);while(t--)
#define ll long long
#define LLINF LLONG_MAX
#define LINF LONG_MAX
#define INF INT_MAX
#define SIZE 100005
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int n,ar[SIZE],k;
	i(n);
	trav(i,1,1+n)
	{
		i(ar[i]);
	}
	i(k);
	set<int>s;
	trav(i,1,1+k)
	{
		s.insert(ar[i]);
	}
	set<int>::iterator m;
	m=s.end();
	m--;
	cout<<*m<<" ";
	trav(i,k+1,n)
	{
		set<int>::iterator prev,M;
		prev=s.find(ar[i-k]);
		s.erase(prev);
		s.insert(ar[i]);
		M=s.end();
		M--;
		cout<<*M<<" ";
	}
	return 0;
}