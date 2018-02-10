#include <bits/stdc++.h>
using namespace std;
bool check(int n)
{
    if(n==1)
    return false;
    if(n==2)
    return true;
    if(n%2==0)
    return false;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main() 
{
	long long int t,n,m;
	cin>>t;
	while(t--)
	{
	    cin>>m>>n;
	    for(int i=m;i<=n;i++)
	    {
	        if(check(i))
	        {
	            cout<<i<<"\n";
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}
