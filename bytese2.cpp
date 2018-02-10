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
map<int,int>m;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		m.clear();
		for(int i=0;i<n;i++)
		{
			int l,r;
			cin>>l>>r;
			m[l]++;
			m[r+1]--;
		}
		map<int,int>::iterator it,prev;
		int ans=-1;
		for(it=m.begin();it!=m.end();it++)
		{
			if(it!=m.begin())
			{
				it->second+=prev->second;
				ans=max(ans,it->second);
			}
			prev=it;	
		}
		cout<<ans<<"\n";
	}
	return 0;
}