#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,m,sum=0,max_sum=LLONG_MIN;
	int ar[300005];
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ar[i]);
	}
	int l=1;
	int r=1;
	while(r<=n)
	{
		sum+=ar[r];
		while(sum>m)
		{
			sum-=ar[l++];
			if(sum==m)
			{
				break;
			}
		}
		max_sum=max(sum,max_sum);
		if(max_sum==m)
		{
			break;
		}
		r++;
	}
	cout<<max_sum<<"\n";
	//getchar();
	//getchar();
	return 0;
}