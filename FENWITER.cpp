#include <bits/stdc++.h>
using namespace std;

int main()
{
	string ar1;
	string ar2;
	string ar3;
	string ar;
	long long int t,n,ans;
	cin>>t;
	while(t--)
	{
		cin>>ar1>>ar2>>ar3>>n;
		int l1=ar1.size();
		int l2=ar2.size();
		int l3=ar3.size();
		ar=ar1+ar2+ar3;
		int l=ar.size();
		int index=-1;
		for(int i=l-1;i>=0;i--)
		{
			if(ar[i]=='0')
			{
				index=i;
				break;
			}
		}
		if(index==-1)
		{	
			ans=1;
		}
		else
		{
			if(index>=(l1+l2))
			{
				ans=1;
				for(int i=l1+l2;i<index;i++)
				{
					if(ar[i]=='1')
					{
						ans++;
					}
				}
				int c=0;
				for(int i=0;i<l2;i++)
				{
					if(ar2[i]=='1')
					{
						c++;
					}
				}
				ans+=n*c;
				for(int i=0;i<l1;i++)
				{
					if(ar1[i]=='1')
					{
						ans++;
					}
				}
			}
			else if(index>=l1 && index<(l1+l2))
			{
				ans=1;
				for(int i=0;i<l1;i++)
				{
					if(ar1[i]=='1')
					{
						ans++;
					}
				}
				//ans+=l3;
				int c=0;
				for(int i=0;i<l2;i++)
				{
					if(ar2[i]=='1')
					{
						c++;
					}
				}
				ans+=(n-1)*c;
				for(int i=l1;i<index;i++)
				{
					if(ar[i]=='1')
					{
						ans++;
					}
				}
			}
			else if(index<l1)
			{
				ans=1;
				//ans+=l3;
				//ans+=n*l2;
				for(int i=0;i<index;i++)
				{
					if(ar[i]=='1')
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}