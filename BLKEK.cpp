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

ll power(ll a, ll n) {
    if (n == 0) {
      return 1;
    }
    ll p = power(a, n / 2);
    p *= p;
    if (n & 1) {
      p = p * a;
    }
    return p;
}

ll gcd(ll a, ll b) {
    if (b) {
      return gcd(b, a % b);
    }
    return a;
}

inline void boostIO() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

string s1, s2;
int dp[2005][5], n, m = 3;
int solve(int i, int j) {

    if(j == m)
        return 1;

    if(i == n)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(s1[i] == s2[j]) {
        dp[i][j] = solve(i + 1, j) + solve(i + 1, j + 1);
    } else {
        dp[i][j] = solve(i + 1, j);
    }

    return dp[i][j];
}

int main() {

    boostIO();
    int t;
    cin >> t;
    s2 = "KEK";
    while(t--) {
        cin >> s1;
        n = s1.length();

        mem(dp, -1);
        cout << solve(0, 0) << "\n";
    }
    return 0;
}