#include <bits/stdc++.h>
using namespace std;
 
char ar[1005][1005];
int vis[1005][1005];
int n,m;
int trap,call;
void dfs(int i,int j)
{
    if(vis[i][j]==0)
    {
        vis[i][j]=call;
    }
    else
    {
        if(vis[i][j]==call)
        {
            return;
        }
        else if(vis[i][j]!=call)
        {
            trap--;
            return;
        }
    }
    if(ar[i][j]=='S')
    {
        //vis[i][j]=call;
        if(i+1<n)
        dfs(i+1,j);
    }
    else if(ar[i][j]=='N')
    {
        //vis[i][j]=call;
        if(i-1>=0)
        dfs(i-1,j);
    }
    else if(ar[i][j]=='E')
    {
        //vis[i][j]=call;
        if(j+1<m)
        dfs(i,j+1);
    }
    else if(ar[i][j]=='W')
    {
        //vis[i][j]=call;
        if(j-1>=0)
        dfs(i,j-1);
    }
}
int main() 
{
	scanf("%d %d",&n,&m);
    int f=0;
    for(int i=0;i<n;i++)
    {
        //vis[i][j]=0;
        scanf("%s",ar[i]);
        /*if(ar[i][j]>=97 && ar[i][j]<=122){
            f=1;//to check whether there is any small letter
        }*/
    }
 
    //cout << "This is start of matrix : " << endl;
 
    for(int i=0; i<n ; i++)
    {
   	    for (int j = 0; j < m; ++j)
   	    {
   	        vis[i][j]=0;
       		if(ar[i][j]>=97 && ar[i][j]<=122)
       		{
       		    f=1;
       		}
   	    }
   	    //cout << "\n"; 
    }
 
   //cout << "this is finish of matrix : "<< endl ; 
 
    if(f!=1)
    {
        trap=0;
        call=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0)
                {
                    dfs(i,j);
                    // print();
                    trap++;
                    call++;
                }
            }
        }
        cout<<trap<<"\n";
    }
    else
    {
        cout<<0<<"\n";
    }
	return 0;
}