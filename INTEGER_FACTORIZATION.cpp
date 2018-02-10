#include <bits/stdc++.h>
using namespace std;

int main() 
{
	long long int n;
	while(1)
	{
	    scanf("%lld",&n);
	    if(n==0)
	    {
	        break;
	    }
	    for(int i=2;(long long)i*i<=n;(i==2)?(i++):(i+=2))
	    {
	        int c=0;
	        if(n%i==0)
	        {
	            while(n%i==0)
	            {
	                c++;
	                n/=i;
	            }
	            printf("%d^%d ",i,c);
	        }
	    }
	    if(n>1)
	    {
	        printf("%lld^1",n);
	    }
	    printf("\n");
	}
	return 0;
}
