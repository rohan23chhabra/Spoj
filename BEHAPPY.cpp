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

int m, n, a[25], b[25];
int dp[25][110];

int solve(int i, int j) {
    if (i == m) { // all girlfriends exhausted.
        if (j)
            return 0;
        return 1;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = 0;
    for (int k = a[i]; k <= b[i]; k++) {
        if(j - k >= 0) {
            dp[i][j] += solve(i + 1, j - k);
        }
    }

    return dp[i][j];
}


int main() {

    boostIO();
    while (1) {

        cin >> m >> n;
        if (m == 0 && n == 0)
            break;

        for (int i = 0; i < m; ++i)
        {
            cin >> a[i] >> b[i];
        }

        mem(dp, -1);
        cout << solve(0, n) << "\n";
    }
    return 0;
}