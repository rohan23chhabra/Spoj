#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long n,m,sum=0,ans=LONG_MIN;
		int ar[100005];
		scanf("%ld %ld",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&ar[i]);
		}
		int l=1,r=1,count=0,max_count=INT_MIN;
		while(r<=n)
		{
			sum+=ar[r];
			count++;
			while(sum>m)
			{
				sum-=ar[l++];
				count--;
			}
			if(count==max_count)
			{
				ans=min(sum,ans);
			}
			else if(count > max_count)
			{
				ans=max(sum,ans);
			}
			max_count=max(count,max_count);
			r++;
		}
		cout<<ans<<" "<<max_count<<"\n";
	}
	//getchar();
	//getchar();
	return 0;
}