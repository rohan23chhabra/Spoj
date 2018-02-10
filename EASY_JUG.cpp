#include <bits/stdc++.h>
using namespace std;
long gcd(long b,long s)
{
    if(b%s==0)
    {
        return s;
    }
    else
    {
        return gcd(s,b%s);
    }
}
int main() 
{
	int t;
	long x,y,z;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%ld %ld %ld",&x,&y,&z);
	    if(z % gcd(max(x,y),min(x,y))==0 && z<=max(x,y))
	    {
	        printf("YES\n");
	    }
	    else
	    {
	        printf("NO\n");
	    }
	}
	return 0;
}
