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
	test
	{
		int h,w;
		ii(h,w);
		int ar[105][105];
		trav(i,0,h)
		{
			trav(j,0,w)
			{
				i(ar[i][j]);
			}
		}
		trav(i,1,h)
		{
			trav(j,0,w)
			{
				if(j==0)
				{
					ar[i][j]+=max(ar[i-1][j],ar[i-1][j+1]);
				}
				else if(j==w-1)
				{
					ar[i][j]+=max(ar[i-1][j],ar[i-1][j-1]);
				}
				else
				{
					ar[i][j]+=max(max(ar[i-1][j-1],ar[i-1][j]),ar[i-1][j+1]);
				}
			}
		}
		int ans=0;
		trav(j,0,w)
		{
			ans=max(ans,ar[h-1][j]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}