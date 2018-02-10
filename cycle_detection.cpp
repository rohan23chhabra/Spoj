#include <bits/stdc++.h>
using namespace std;
int parent[100000];
int u[100000],v[100000];
int rank[100000];
int find(int s)
{
	if(parent[s]==s)
	{
		return s;
	}
	return (parent[s]=find(parent[s]));//Path compression
}
void unionSet(int l1,int l2)
{
	if(rank[l1]>rank[l2])
	{
		parent[l2]=l1;
	}
	else if(rank[l2]>rank[l1])
	{
		parent[l1]=l2;
	}
	else
	{
		parent[l1]=l2;
		rank[l2]++;
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		cin>>u[i]>>v[i];
	}
	int flag=0;
	for(int i=0;i<m;i++)
	{
		int leader1=find(u[i]);
		int leader2=find(v[i]);
		if(leader1!=leader2)
		{
			unionSet(leader1,leader2);//Unite the leaders not the individual vertices!!
		}
		else
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		cout<<"Cycle in graph\n";
	}
	else
	{
		cout<<"No cycle\n";
	}
	return 0;
}