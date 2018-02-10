#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define ll long long
#define SIZE 100005
#define ff first
#define ss second
#define X real()
#define Y imag()
#define sz(a) sizeof(a) 
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
typedef complex<double> point;
const int mod=1000000007;
const ll INF=1e10;
ll dis[10][10];
int a,b,c,d;
int ar[8][2]={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
bool isSafe(int x,int y)
{
	if(x<0 || x>7 || y<0 || y>7)
		return false;
	return true;
}
int bfs()
{
	priority_queue<iii,vector<iii>,greater<iii> >q;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			dis[i][j]=INF;
		}
	}
	dis[a][b]=0;
	int vis[10][10];
	memset(vis,0,sz(vis));
	q.push(mp(0,mp(a,b)));
	while(!q.empty())
	{
		iii p=q.top();
		q.pop();
		int x0=p.ss.ff;
		int y0=p.ss.ss;
		if(x0==c && y0==d)
			return dis[x0][y0];
		if(vis[x0][y0])
			continue;
		vis[x0][y0]=1;
		for(int k=0;k<8;k++)
		{
			int x=ar[k][0]+x0;
			int y=ar[k][1]+y0;
			if(isSafe(x,y))
			{
				if(dis[x][y]>x*x0+y*y0+dis[x0][y0])
				{
					dis[x][y]=x*x0+y*y0+dis[x0][y0];
					q.push(mp(dis[x][y],mp(x,y)));
				}
			}
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	while(scanf("%d %d %d %d",&a,&b,&c,&d)==4)
	{
		cout<<bfs()<<"\n";
	}
	return 0;
}