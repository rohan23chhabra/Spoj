#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t,s,n,ar[1005],ans,sum,c;
	cin>>t;
	for(int x=1;x<=t;x++)
	{
	    ans=sum=c=0;
	    cin>>s>>n;
	    for(int i=0;i<n;i++)
	    {
	        cin>>ar[i];
	    }
	    sort(ar,ar+n);
	    int flag=0;
	    for(int i=n-1;i>=0;i--)
	    {
	        sum+=ar[i];
	        c++;
	        if(sum>=s)
	        {
	            flag=1;
	            break;
	        }
	    }
	    cout<<"Scenario #"<<x<<":\n";
	    if(flag==1)
	    cout<<c<<"\n";
	    else
	    cout<<"impossible\n";
	    cout<<"\n";
	}
	return 0;
}
