#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	int t,n,c,temp;
	int ar[200];
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    c=1;
	    ar[0]=1;
	    for(int i=1;i<=n;i++)
	    {
    	    temp=0;
            for(int j=0;j<c;j++)
            {
                temp=ar[j]*i+temp;
                ar[j]=temp%10;
                temp/=10;
            }
            while(temp!=0)
            {
                ar[c]=temp%10;
                temp/=10;
                c++;
            }
	    }
	    for(int i=c-1;i>=0;i--)
	    {
	        cout<<ar[i];
	    }
	    cout<<"\n";
	}
	return 0;
}