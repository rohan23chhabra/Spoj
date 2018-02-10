#include <bits/stdc++.h>
using namespace std;

int x[10]={0,-1,-1,-2,-2,2,2,1,1};
int y[10]={0,-2,2,-1,1,-1,1,-2,2};
int bfs(int s_x,int s_y,int d_x,int d_y)
{
    int d[100][100];
    int flag[100][100];
    memset(d,0,sizeof(d));
    memset(flag,0,sizeof(flag));
    queue<pair<int,int> >q;
    pair<int,int>p,temp;
    p=make_pair(s_x,s_y);
    q.push(p);
    flag[s_x][s_y]=0;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        if(p.first==d_x && p.second==d_y)
        {
            return d[d_x][d_y];
        }
        for(int a=1;a<=8;a++)
        {
            int i=p.first+x[a];
            int j=p.second+y[a];
            if(i<1 || i>8 || j<1 || j>8)
            {
                continue;
            }
            else
            {
                flag[i][j]=1;
                d[i][j]=1+d[p.first][p.second];
                q.push(make_pair(i,j));
            }
        }
    }
}
int main() 
{
	long long int t;
	scanf("%lld",&t);
	char s1[10],s2[10];
	while(t--)
	{
	    cin>>s1>>s2;
	    int s_x=s1[0]-96;
	    int s_y=s1[1]-48;
	    int d_x=s2[0]-96;
	    int d_y=s2[1]-48;
	    cout<<bfs(s_x,s_y,d_x,d_y)<<"\n";
	}
	return 0;
}