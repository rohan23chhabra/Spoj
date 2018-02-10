#include <bits/stdc++.h>
using namespace std;

int main() 
{
	char s[1000000];
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        cin>>s[i];
	    }
	    s[n]='\0';
	    bool val=next_permutation(s,s+n);
	    if(!val)
	    {
	        cout<<-1<<"\n";
	    }
	    else
	    {
	        cout<<s<<"\n";
	    }
	}
	return 0;
}
