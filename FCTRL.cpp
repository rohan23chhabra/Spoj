#include <bits/stdc++.h>
using namespace std;

int main() 
{
	long fives[]={5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625,1220703125},n,ans;
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%ld",&n);
	    ans=i=0;
	    while((n/fives[i])!=0)
	    {
	        ans+=n/fives[i];
	        i++;
	    }
	    printf("%ld\n",ans);
	}
	return 0;
}
