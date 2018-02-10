#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t,n,m[1005],w[1005],ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>m[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>w[i];
        }
        sort(m,m+n);
        sort(w,w+n);
        for(int i=n-1;i>=0;i--)
        {
            ans+=m[i]*w[i];
        }
        cout<<ans<<"\n";
    }
    
	return 0;
}
