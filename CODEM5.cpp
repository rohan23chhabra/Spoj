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
const int N = 10002;

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

int n, k, ar[25], dp[25][N];

int solve(int i, int w) {

    if(w == 0) 
        return 0;

    if(i == n || w < 0) {
        return 100000000;
    }
    
    if(dp[i][w] != -1)
        return dp[i][w]; 

    return dp[i][w] = min (solve(i + 1, w), 1 + solve(i + 1, w - ar[i]));
    
}

int main() {

    boostIO();
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;

        for (int i = 0; i < n; ++i)
        {
            cin >> ar[i];
        }

        mem(dp, -1);
        int ans = solve(0, k);
        if(ans < 100000000)
            cout << ans << "\n";
        else
            cout << "impossible\n";
    }
    return 0;
}