#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t,n,f;
	int ar[10000];
	long double area[10000];
	long double pi=3.14159265358979323846264338327950,expo=pow(10,-6);
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d %d",&n,&f);
	    f++;
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&ar[i]);
	    }
	    sort(ar,ar+n);
	    for(int i=0;i<n;i++)
	    {
	        area[i]=ar[i]*ar[i]*pi;
	    }
	    long double high=area[n-1];
	    long double low=0;
	    while(high-low>=expo)
	    {
	        long double x=(low+high)/2;
	        if(x==0)
	        {
	            high=x;
	            continue;
	        }
	        int fr=0;
	        for(int i=n-1;i>=0;i--)
	        {
	            fr+=(int)(area[i]/x);
	        }
	        if(fr>=f)
	        {
	            low=x;
	        }
	        else
	        {
	            high=x;
	        }
	    }
	    printf("%.4llf\n",low);
	}
	return 0;
}
