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
const int mod = 100000007;
const long double eps = 1e-6;
const int N = 100002;

inline void boostIO() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n, m, a[1025], f[1025];
int dp[1025][1025];


int main() {

    boostIO();
    int t;
    cin >> t;
    for(int c = 1; c <= t; c++) {

        cin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        mem(f, 0);

        for (int i = 0; i < m; ++i)
        {
            int b;
            cin >> b;
            f[b] = 1;
        }
        mem(dp, 0);
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 1024; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j ^ a[i - 1]];
                dp[i][j] %= mod;
            }
        }
        
        int ans = 0;
        
        for(int j = 0; j < 1024; j++) {
            if(f[j] == 0) {
                ans += dp[n][j];
                ans %= mod;
            } 
        }
        
        printf("Case %d: %d\n",c,ans);
    }
    return 0;
}