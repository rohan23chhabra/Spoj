#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
typedef pair<int, int> iPair;
vector<pair<int,int> >adj[100005];
int n;
long long int prim()
{
	long long int ans=0;
	int s=1,c=0;
	vector<int>key(n+5,inf);//store corresponding weights
	vector<bool>intree(n+5,false);//check whether node i is in the tree
	vector<bool>popped(n+5,false);//to check whether a vertex has been popped out of the priority_queue
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
	pq.push(make_pair(0,s));
	key[s]=0;//Assigning a weight of zero to the source node
	while(!pq.empty())
	{
		c++;
		if(c==n+1)
		{
		    break;
		}
		int u=pq.top().second;
		//cout<<pq.top().first<<" "<<pq.top().second<<"\n";
		if(popped[u])
		{
		    pq.pop();
		    c--;
		    continue;
		}
		ans+=pq.top().first;
		pq.pop();//Extract minimum from the priority queue followed by deleting from the queue
		popped[u]=true;
		intree[u]=true;//Include the vertex in the minimum spanning tree
		vector<pair<int,int> >::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();i++)
		{
			int v=(*i).first;
			int weight=(*i).second;
			if(intree[v]==false && key[v]>weight)
			{
				key[v]=weight;
				pq.push(make_pair(key[v],v));
			}
		}
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,u,v,w,p;
		cin>>p>>n>>m;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			adj[u].push_back(make_pair(v,w));
			adj[v].push_back(make_pair(u,w));
		}
		cout<<p*prim()<<"\n";
	}
	return 0;
}