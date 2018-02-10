#include <bits/stdc++.h>
using namespace std;

int main() 
{
	set <int> s;
	map <int,int> m;
	char ar[10];
	int n,k,c=0;
	scanf("%d",&n);
	while(n--)
	{
	    scanf("%s %d",ar,&k);
	    if(ar[0]=='i')
	    {
	        c++;
	        s.insert(k);
	        m[k]++;
	    }
	    else
	    {
	        set<int>::iterator it=s.find(k);
	        if(it!=s.end())
	        {
	            c--;
	            if(m[k]==1)
	            {
	                s.erase(k);
	            }
	            m[k]--;
	        }
	    }
	    if(s.size()==1)
	    {
	        if(c==1)
	        {
	            printf("neither\n");
	        }
	        else if(c>1)
	        {
	            printf("homo\n");
	        }
	    }
	    else if(s.size()<=0)
	    {
	        printf("neither\n");
	    }
	    else if(s.size()>1)
	    {
	        if(c>s.size())
	        {
	            printf("both\n");
	        }
	        else if(c==s.size())
	        {
	            printf("hetero\n");
	        }
	    }
	}
	return 0;
}
