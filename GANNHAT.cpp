#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define maxn 100005
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define pi 3.141592653589793
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
typedef long long ll;
const int mod=1000000007;
const long double eps=1e-6;
ll power(ll a,ll n) {if(n==0){return 1;}ll p=power(a,n/2);p=p*p;if(n&1){p=p*a;}return p;}
ll gcd(ll a,ll b) {if(b){return gcd(b,a%b);}return a;}

int main() {
	boost
	int n;
	cin>>n;
	int x[2*maxn],y[2*maxn];
	vector<ii>xc,yc;
	for(int i=0;i<n;i++) {
		cin>>x[i]>>y[i];
		int s = x[i] + y[i];
		int d = x[i] - y[i];
		x[i] = d;
		y[i] = s;
		xc.pb(mp(x[i],i));
		yc.pb(mp(y[i],i));
	}
	sort(xc.begin(),xc.end());
	sort(yc.begin(),yc.end());
	for(int i=0;i<n;i++) {
		int X,Y;
		if(xc[0].ss != i)
			X = abs(x[i] - xc[0].ff);
		else
			X = abs(x[i] - xc[1].ff);
		if(xc[n-1].ss != i)
			X = max(X, abs(x[i] - xc[n-1].ff));
		else
			X = max(X, abs(x[i] - xc[n-2].ff));

		if(yc[0].ss != i)
			Y = abs(y[i] - yc[0].ff);
		else
			Y = abs(y[i] - yc[1].ff);
		if(yc[n-1].ss != i)
			Y = max(Y, abs(y[i] - yc[n-1].ff));
		else
			Y = max(Y, abs(y[i] - yc[n-2].ff));

		cout<<max(X, Y)<<"\n";
	}

	return 0;
}
