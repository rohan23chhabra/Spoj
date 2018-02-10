#include <bits/stdc++.h>
using namespace std;
int factors(int n)
{
    int ans=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans++;
        }
    }
    return ans;
}
int prime[10000005];
int main() 
{
	int n;
	memset(prime,0,sizeof(prime));
	for(int i=2;(long long)i*i<=10000005;i++)
	{
	    if(prime[i]==0)
	    {
	        for(int j=i*i;j<=10000005;j+=i)
	        {
	            if(prime[j]==0)
	            prime[j]=i;
	        }
	    }
	}
	int primefact[1000],c,temp;
	while(1)
	{
	    c=0;
	    cin>>n;
	    temp=n;
	    if(n==0)
	    {
	        break;
	    }
	    while(prime[n]!=0)
	    {
	        primefact[c++]=prime[n];
	        n=n/prime[n];
	    }
	    primefact[c++]=n;
	    printf("%d = ",temp);
	    for(int i=0;i<c-1;i++)
	    {
	        printf("%d * ",primefact[i]);
	    }
	    printf("%d",primefact[c-1]);
	    printf("\n");
	    printf("With %d marbles, %d different rectangles can be constructed.\n",temp,factors(temp));
	}
	return 0;
}
