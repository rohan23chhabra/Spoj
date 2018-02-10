#include <iostream>
using namespace std;

int di[]={-1,-1,-1,0,0,1,1,1};
int dj[]={-1,0,1,-1,1,-1,0,1};
char ar[52][52];
int vis[52][52];
int n,m;
int final_ans=0;
void dfs(int i,int j,int ans)
{
    final_ans=max(ans,final_ans);
    for(int x=0;x<8;x++)
    {
        int p=i+di[x];
        int q=j+dj[x];
        if((p>=0 && p<n) && (q>=0 && q<m) && !vis[p][q])
        {
            if(ar[p][q]-ar[i][j]==1)
            {
                vis[p][q]=1;
                dfs(p,q,1+ans);
            }
        }
    }
}
int main() 
{
	int t=0;
	while(1)
	{
	    cin>>n>>m;
	    if(n==0 && m==0)
	    {
	        break;
	    }
	    t++;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cin>>ar[i][j];
	            vis[i][j]=0;
	        }
	    }
	    final_ans=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(ar[i][j]=='A')
	            {
	                vis[i][j]=1;
	                dfs(i,j,1);
	            }
	        }
	    }
	    cout<<"Case "<<t<<": "<<final_ans<<"\n";
	}
	return 0;
}
