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
int translate(string a)
{
	int n=0;
	n=n*10+(int)(a[0]-48);
	n=n*10+(int)(a[1]-48);
	while((a[3]-48))
	{
		n*=10;
		a[3]--;
	}
	return n;
}
int main()
{
	ios::sync_with_stdio(false);
	string a;
	while(1)
	{
		cin>>a;
		int n=translate(a);
		if(n==0)
			break;
		int x=1;
		while(x<=n)
		{
			x*=2;
		}
		cout<<1+2*n-x<<"\n";
	}
	return 0;
}