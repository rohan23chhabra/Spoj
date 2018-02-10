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
struct node
{
	int count;
	int lazy;
}tree[4*SIZE];
void toggle(int i,int s,int e,int l,int r)
{
	if(tree[i].lazy%2)
	{
		tree[i].count=e-s+1-tree[i].count;
		if(s!=e)
		{
			tree[2*i].lazy+=tree[i].lazy;
			tree[2*i+1].lazy+=tree[i].lazy;
		}
		tree[i].lazy=0;
	}
	if(s>e || s>r || e<l)
	{
		return;
	}
	if(s>=l && e<=r)
	{
		tree[i].count=e-s+1-tree[i].count;
		if(s!=e)
		{
			tree[2*i].lazy++;
			tree[2*i+1].lazy++;
		}
		return;
	}
	int mid=(s+e)/2;
	toggle(2*i,s,mid,l,r);
	toggle(2*i+1,mid+1,e,l,r);
	tree[i].count=tree[2*i].count+tree[2*i+1].count;
}
int query(int i,int s,int e,int l,int r)
{
	if(tree[i].lazy%2)
	{
		tree[i].count=e-s+1-tree[i].count;
		if(s!=e)
		{
			tree[2*i].lazy+=tree[i].lazy;
			tree[2*i+1].lazy+=tree[i].lazy;
		}
		tree[i].lazy=0;
	}
	if(s>e || s>r || e<l)
	{
		return 0;
	}
	if(s>=l && e<=r)
	{
		return tree[i].count;
	}
	int mid=(s+e)/2;
	return query(2*i,s,mid,l,r)+query(2*i+1,mid+1,e,l,r);
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int type,l,r;
		cin>>type;
		if(!type)
		{
			cin>>l>>r;
			toggle(1,0,n-1,--l,--r);
		}
		else
		{
			cin>>l>>r;
			cout<<query(1,0,n-1,--l,--r)<<"\n";
		}
	}
	return 0;
}