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
struct nodes
{
	int m;
}tree[4*SIZE];
int ar[SIZE];
void build(int node,int s,int e)
{
	if(s==e)
	{
		tree[node].m=ar[s];
		return;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	tree[node].m=min(tree[2*node].m,tree[2*node+1].m);
}
long query(int node,int s,int e,int l,int r)
{
	if(s>e || s>r || e<l)
	{
		return LONG_MAX;
	}
	if(s>=l && e<=r)
	{
		return tree[node].m;
	}
	int mid=(s+e)/2;
	return min(query(2*node,s,mid,l,r),query(2*node+1,mid+1,e,l,r));
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		for(int i=0;i<n;i++)
			cin>>ar[i];
		build(1,0,n-1);
		for(int i=0;i<q;i++)
		{
			int l,r;
			cin>>l>>r;
			cout<<query(1,0,n-1,--l,--r)<<"\n";
		}
	}
	return 0;
}