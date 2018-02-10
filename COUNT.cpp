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
//const int N = 100002;

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
int N, K, dp[5002][5002];

int solve(int n, int k) {

    if (n < 0)
        return 0;
    
    if (n == 0)
        return 1;

    if (k == 0)
        return 0;

    if (dp[n][k] != -1)
        return dp[n][k];

    return dp[n][k] = (solve(n, k - 1) + solve(n - k, k)) % 1988;
}

int main() {

    boostIO();
    while (true) 
    {
        cin >> N >> K;

        if (N == 0 && K == 0) {
            break;
        }

        mem(dp, -1);
        cout << (solve(N, K) - solve(N, K - 1) + 1988) % 1988 << "\n";
    }
    return 0;
}