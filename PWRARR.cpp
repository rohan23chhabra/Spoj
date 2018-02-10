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
#define ff first
#define ss second
#define X real()
#define Y imag()
#define sz(a) sizeof(a) 
using namespace std;
typedef pair<int,int> ii;
typedef complex<double> point;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ar[50002];
		for(int i=0;i<n;i++)
			cin>>ar[i];
		sort(ar,ar+n);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			ans+=upper_bound(ar,ar+n,ar[i])-ar;
		}
		cout<<ans<<"\n";
	}
	return 0;
}