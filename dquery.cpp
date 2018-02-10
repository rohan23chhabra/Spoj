#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define ll long long
#define SIZE 100005
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define pi 3.141592653589793
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
const int mod=1000000007;
const ll INF=1e9;
const long double eps=1e-6;
int cnt[10*SIZE],B,ans[2*SIZE],answer=0,ar[SIZE];
struct node
{
	int l,r,i;
}q[2*SIZE];
bool cmp(node x,node y)
{
	if(x.l/B!=y.l/B)
		return x.l/B < y.l/B;
	return x.r < y.r;
}
void add(int pos)
{
	cnt[ar[pos]]++;
	if(cnt[ar[pos]]==1)
		answer++;
}
void rem(int pos)
{
	cnt[ar[pos]]--;
	if(cnt[ar[pos]]==0)
		answer--;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n;
	B=sqrt(n);
	for(int i=0;i<n;i++)
		cin>>ar[i];
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>q[i].l>>q[i].r;
		q[i].l--;
		q[i].r--;
		q[i].i=i;
	}
	sort(q,q+m,cmp);
	int curL=0,curR=0;
	for(int i=0;i<m;i++)
	{
		int l=q[i].l;
		int r=q[i].r;
		while(curL<l)
		{
			rem(curL);
			curL++;
		}
		while(curL>l)
		{
			curL--;
			add(curL);
		}
		while(curR>r+1)
		{
			rem(curR-1);
			curR--;
		}
		while(curR<=r)
		{
			add(curR);
			curR++;
		}
		ans[q[i].i]=answer;
	}
	for(int i=0;i<m;i++)
	{
		cout<<ans[i]<<"\n";
	}
	return 0;
}