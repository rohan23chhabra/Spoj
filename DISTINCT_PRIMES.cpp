#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int prime[10000];
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=10000;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*2;j<=10000;j+=i)
            {
                prime[j]++;
            }
        }
    }
    int ans[10000];
    int c=1;
    for(int i=30;i<=10000;i++)
    {
        if(prime[i]>=3)
        {
            ans[c++]=i;
        }
    }
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
