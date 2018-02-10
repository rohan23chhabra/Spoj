#include <bits/stdc++.h>
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
const int mod=1000000007;
int x[1002],y[1002];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		for(int i=1;i<=m-1;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n-1;i++)
		{
			cin>>y[i];
		}
		ll ans=0;
		sort(x+1,x+m,greater<int>());
		sort(y+1,y+n,greater<int>());
		int i=1,j=1;
		int ch=1,cv=1;
		while(i<m && j<n)
		{
			if(x[i]>y[j])
			{
				ans+=x[i]*cv;
				i++;
				ch++;
			}
			else
			{
				ans+=y[j]*ch;
				j++;
				cv++;
			}
		}
		while(i<m)
		{
			ans+=x[i]*cv;
			i++;
		}
		while(j<n)
		{
			ans+=y[j]*ch;
			j++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}