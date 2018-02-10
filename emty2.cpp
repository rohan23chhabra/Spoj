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
#define pi 3.141592653589793
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
const int mod=1000000007;
const ll INF=1e9;
const long double eps=1e-6;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int x=1;x<=t;x++)
	{
		string ar;
		cin>>ar;
		int bal=0;
		for(int i=0;i<ar.size();i++)
		{
			if(ar[i]=='1')
				bal+=2;
			else
				bal--;
			if(bal<0)
				break;
		}
		if(bal)
		{
			cout<<"Case "<<x<<": no\n";
		}
		else
		{
			cout<<"Case "<<x<<": yes\n";
		}
	}
	return 0;
}