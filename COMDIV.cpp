#include <bits/stdc++.h>
using namespace std;
int gcd(int s,int b)
{
    if(s>b)
    {
        gcd(b,s);
    }
    if(b%s==0)
    {
        return s;
    }
    else
    {
        return gcd(b%s,s);
    }
}
int main() 
{
	int t,a,b,ans;
	scanf("%d",&t);
	while(t--)
	{
	    ans=0;
	    scanf("%d %d",&a,&b);
	    int hcf=gcd(a,b),i;
	    int flag=0;
	    for(i=1;(long long int)i*i<=hcf;i++)
	    {
	        if(hcf%i==0)
	        {
	            if(i==hcf/i)
	            {
	                flag=1;
	            }
	            ans++;
	        }
	    }
	    if(flag!=1)
	    printf("%d\n",2*ans);
	    else
	    printf("%d\n",2*ans-1);
	}
	return 0;
}

