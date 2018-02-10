#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define ll long long
#define SIZE 100005
#define ff first
#define ss second
#define sz(a) sizeof(a) 
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
const int mod=1000000007;
const ll INF=1e10;
int dp[82][82];
int lcslen=0;
string s1,s2;
int n1,n2;
char ar[100];
int solve(int i,int j)
{
	if(i==n1 || j==n2)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(s1[i]==s2[j])
		return dp[i][j]=1+solve(i+1,j+1);
	else
		return dp[i][j]=max(solve(i+1,j),solve(i,j+1));
}
void print(int i,int j,int curlcs)
{
	if(curlcs==lcslen)
	{
		ar[lcslen]='\0';
		cout<<ar<<"\n";
		return;
	}

	for(char c='a';c<='z';c++)
	{
		bool done=false;
		for(int x=i;x<n1;x++)
		{
			if(c==s1[x])
			{
				for(int y=j;y<n2;y++)
				{
					if(c==s2[y] && solve(x,y)==lcslen-curlcs)//not tle as dp[][] is already memoized.
					{
						ar[curlcs]=c;
						print(x+1,y+1,curlcs+1);
						done=true;
						break;
					}
				}
			}
			if(done)
				break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s1>>s2;
		n1=s1.size();
		n2=s2.size();
		mem(dp,-1);
		lcslen=solve(0,0);
		print(0,0,0);
	}
	return 0;
}