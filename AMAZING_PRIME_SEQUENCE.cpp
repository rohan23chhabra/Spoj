#include <bits/stdc++.h>
using namespace std;
long long int a[10000001];
int f[10000001];
int main() 
{
    memset(f,0,sizeof(f));
    for(int i=2;i<=10000000;i++)
    {
        if(f[i]==0)
        {
            for(int j=i*2;j<=10000000;j+=i)
            {
                if(f[j]==0)
                f[j]=i;
            }
        }
    }
    a[0]=a[1]=0;
    for(int i=2;i<=10000000;i++)
    {
        if(f[i]==0)
        {
            f[i]=i;
        }
        a[i]=a[i-1]+f[i];
    }
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    printf("%lld\n",a[n]);
	}
	return 0;
}
