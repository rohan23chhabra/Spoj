#include <bits/stdc++.h>
using namespace std;
long factors(int n)
{
    long ans=0;
    for(int i=1;(long)i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans++;
        }
    }
    return ans;
}
int main() 
{
	int n;
	cin>>n;
	if(n==1 || n==2 || n==3)
	{
	    cout<<n;
	}
	else
	{
	    long long int sum=3;
	    for(int i=4;i<=n;i++)
	    {
	        sum+=factors(i);
	    }
	    cout<<sum;
	}
	return 0;
}
