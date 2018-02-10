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
	int n1,n2,ar1[SIZE],ar2[SIZE];
	int c1[SIZE],c2[SIZE];
	vector<int>i1,i2;
	while(1)
	{
	    i1.clear();
	    i2.clear();
		c1[0]=c2[0]=0;
		i(n1);
		if(n1==0)
			break;
		trav(i,1,1+n1)
		{
			i(ar1[i]);
			c1[i]=ar1[i]+c1[i-1];
		}
		i(n2);
		trav(i,1,1+n2)
		{
			i(ar2[i]);
			c2[i]=ar2[i]+c2[i-1];
		}
		i1.pb(0);
		i2.pb(0);
		int i=1,j=1;
		while(i<=n1 && j<=n2)
		{
			if(ar1[i]==ar2[j])
			{
				i1.pb(i);
				i2.pb(j);
				i++;
				j++;
			}
			else if(ar1[i]>ar2[j])
			{
				j++;
			}
			else
			{
				i++;
			}
		}
		i1.pb(n1);
		i2.pb(n2);
		ll ans=0;
		int n=i1.size();
		trav(i,1,n)
		{
			int s1=c1[i1[i]]-c1[i1[i-1]];
			int s2=c2[i2[i]]-c2[i2[i-1]];
			ans+=max(s1,s2);
		}
		cout<<ans<<"\n";
	}
	return 0;
}