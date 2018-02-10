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
	int t;
	cin>>t;
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		int ar[502][502];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
				cin>>ar[i][j];
		}
		int ans=-1000000;
		for(int j=1;j<c;j++)
		{
			ar[0][j]+=ar[0][j-1];
			if(ar[0][j]<0)
				ans=max(ans,ar[0][j]);
		}
		for(int i=1;i<r;i++)
		{
			ar[i][0]+=ar[i-1][0];
			if(ar[i][0]<0)
				ans=max(ans,ar[i][0]);
		}
		for(int i=1;i<r;i++)
		{
			for(int j=1;j<c;j++)
			{
				ar[i][j]+=max(ar[i-1][j],ar[i][j-1]);
				if(ar[i][j]<0)
				{
					ans=max(ans,ar[i][j]);
				}
			}
		}
		if(ans==-1000000)
		{
			cout<<"1\n";
		}
		else
		{
			cout<<1+abs(ans)<<"\n";
		}
	}
	return 0;
}