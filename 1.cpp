#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ll n,l,r;
	cin>>n>>l>>r;
	ll a[100002],c[100002],b[100002];
	ll p;
	for(ll i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	for(ll i=0;i<n;i++)
	{
	    cin>>c[i];
	}
	for(ll i=0;i<n;i++)
	{
	    b[i]=a[i]+c[i];
	}
	ll m=b[0],M=b[0];
	for(int i=1;i<n;i++)
	{
	    m=min(m,b[i]);
	    M=max(M,b[i]);
	}
	ll shift;
	int flag;
	if(m<l && M<l)
	{
	    flag=0;
	    ll a1=l-m;
	    if(a1+M>r)
	    flag=1;
	    if(flag!=1)
	    shift=a1;
	}
	else if(m<l && (M>=l && M<=r))
	{
	    ll a2=l-m;
	    if(a2+M>r)
	    flag=1;
	    if(flag!=1)
	    shift=a2;
	}
	else if((m>=l && m<=r) && M>r)
	{
	    ll a3=M-r;
	    if(m-a3<l)
	    flag=1;
	    if(flag!=1)
	    shift=-a3;
	}
	else if(m>r && M>r)
	{
	    ll a4=M-r;
	    if(m-a4<l)
	    flag=1;
	    if(flag!=1)
	    shift=-a4;
	}
	if(flag)
	{
	    cout<<"-1";
	}
	else
	{
	    for(int i=0;i<n;i++)
	    {
	        cout<<b[i]+shift<<" ";
	    }
	}
	return 0;
}
