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
int main()
{
	ios::sync_with_stdio(false);
	ll ar[101][150];
	mem(ar,0);
	for(int i=0;i<101;i++)
	{
		if(i==0)
			ar[i][0]=1;
		ar[i][i]=1;
	}
	for(int i=2;i<=100;i++)
	{
		for(int j=2;j<=101;j++)
			ar[i][j]=ar[i-1][j]+ar[i-1][j-1];
	}
	int t;
	cin>>t;
	while(t--)
	{
		int x,n;
		cin>>x>>n;
		cout<<x<<" "<<ar[9+n][n]<<"\n";
	}
	return 0;
}