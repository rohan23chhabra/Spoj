#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define ll long long
#define SIZE 100005
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define pi 3.141592653589793
#define nl cout<<"\n"
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
const int mod=1000000007;
const ll INF=1e9;
const long double eps=1e-6;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int solve(int a,int b,int c)
{
	int ans=1;
	int p=a,q=0;
	while(p!=c && q!=c)
	{
		int transfer=min(p,b-q);
		p-=transfer;
		q+=transfer;
		ans++;
		if(p==c || q==c)
			break;
		if(p==0)
		{
			p=a;
			ans++;
		}
		if(q==b)
		{
			q=0;
			ans++;
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(c%gcd(a,b) || c>max(a,b))
		{
			cout<<"-1\n";
			continue;
		}
		cout<<min(solve(a,b,c),solve(b,a,c))<<"\n";
	}
	return 0;
}