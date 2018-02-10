#include <bits/stdc++.h>
using namespace std;
int main() 
{
	long long int t,n,i;
	cin>>t;
	char ar[]="umank";
	while(t--)
	{
	    char s[1000000];
	    cin>>n;
	    i=0;
	    while(n>0)
	    {
	        s[i++]=ar[n%5];
	        if(n%5==0)
	        n--;
	        n=n/5;
	    }
	    i--;
	    for(int j=i;j>=0;j--)
	    {
	        cout<<s[j];
	    }
	    cout<<"\n";
	}
	return 0;
}
