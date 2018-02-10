#include <bits/stdc++.h>
using namespace std;
int mod(char ar[],int a,int n)
{
    int rem=0;
    for(int i=0;i<n;i++)
    {
        rem=10*rem+(ar[i]-48);
        rem%=a;
    }
    return rem;
}
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main() 
{
	char ar[255];
	int a,t,n;
	cin>>t;
	while(t--)
	{
	    cin>>a>>ar;
	    n=strlen(ar);
	    if(a==0)
	    {
	        cout<<ar<<"\n";
	    }
	    else
	    {
	        cout<<gcd(a,mod(ar,a,n))<<"\n";
	    }
	}
	return 0;
}
