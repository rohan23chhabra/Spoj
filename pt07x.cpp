#include <bits/stdc++.h> 
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mem(a, b) memset(a, b, sizeof(a))
#define pi 3.141592653589793
using namespace std;
typedef pair < int, int > ii;
typedef pair < int, pair < int, int > > iii;
typedef long long ll;
const int mod = 1000000007;
const long double eps = 1e-6;
const int N = 100002;

int n;
vector<int>g[N];
int dp[N][2];

inline void boostIO() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve(int node, int par) {
    dp[node][1] = 1;

    for (int i = 0; i < g[node].size(); i++) {
        int child = g[node][i];
        if(child == par) 
            continue;
        solve(child, node);
        dp[node][1] += min(dp[child][0], dp[child][1]);
        dp[node][0] += dp[child][1];
    }
}

int main() {

    boostIO();
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    solve(1, 0);
    cout << max(1, min(dp[1][0], dp[1][1]));
    return 0;
}