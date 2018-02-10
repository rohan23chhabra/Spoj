#include <bits/stdc++.h>
using namespace std;
long sum[500001];
int main() 
{
    memset(sum,0,sizeof(sum));
	for(int i=1;i<500001;i++)
	{
	    for(int j=i;j<500001;j+=i)
	    {
	        sum[j]+=i;
	    }
	}
	for(int i=1;i<500001;i++)
	{
	    sum[i]-=i;
	}
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    printf("%ld\n",sum[n]);
	}
	return 0;
}
