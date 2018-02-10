#include <bits/stdc++.h>
using namespace std;
int phi[1000001];
int depth[20][1000001];
int dp[1000001];
void precompute()
{
    memset(phi,0,sizeof(phi));
    for(int i=1;i<1000001;i++) 
    {
        phi[i]=i;
    }
    for(int i=2;i<1000001;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<1000001;j+=i)
            {
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }
    }
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<1000001;i++)
    {
        dp[i]=1+dp[phi[i]];
    }
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<1000001;j++)
        {
            depth[i][j]=0;
        }
    }
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<1000001;j++)
        {
            if(dp[j]==i)
            depth[i][j]=1+depth[i][j-1];
            else
            depth[i][j]=depth[i][j-1];
        }
    }
}
int main() 
{
    precompute();
    int t,m,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&m,&n,&k);
        printf("%d\n",(depth[k][n]-depth[k][m-1]));
    }
    return 0;
}
