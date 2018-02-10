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

inline void boostIO() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

string s1, s2;
int k, n, m;
ll dp[102][102][102];

ll solve(int i, int j, int len) {
    if(len == 0)
        return 0;
    
    if (i == n || j == m) 
        return -100000000000;

    ll &ans = dp[i][j][len];

    if (ans != -1)
        return ans;

    ans = max(solve(i + 1, j, len), solve(i, j + 1, len)); // not taking because they aren't equal.
    if(s1[i] == s2[j]) {
        ans = max(ans, s1[i] + solve(i + 1, j + 1, len - 1));
    } 
    return ans;
}

int main() {

    boostIO();
    
    int t;
    cin >> t;
    while (t--) {
        cin >> s1 >> s2 >> k;
        n = s1.length();
        m = s2.length();

        mem(dp, -1);
        ll ans = solve(0, 0, k);
        if(ans >= 0)
            cout << ans << "\n";
        else
            cout << "0\n";
    }
    return 0;
}