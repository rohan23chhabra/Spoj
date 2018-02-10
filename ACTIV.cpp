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
const int N = 100009;

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

inline ll gcd(ll a, ll b) {
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
vector<ii> v;
ll dp[N], ans[N];

int main() {

    boostIO();
    while (true) {

        int n;
        cin >> n;
        if (n == -1)
            break;

        for (int i = 0; i < n; ++i)
        {
            int a, b;
            cin >> a >> b;
            v.pb(mp(a, b));
        }

        sort(v.begin(), v.end());
        ans[n - 1] = 1;
        dp[n - 1] = 1;

        for(int i = n - 2; i >= 0; --i) {

            int low = i + 1, high = n - 1;

            while (low <= high) {
                int mid = (low + high) >> 1;
                if(v[mid].F == v[i].S) {
                    low = mid;
                    break;
                } else if(v[mid].F < v[i].S) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (low > n - 1) {
                ans[low] = 0;
                dp[low] = 0;
            }

            ans[i] = 1 + dp[low];
            dp[i] = dp[i + 1] + ans[i];
        }

        dp[0] %= 100000000;
        int l = 1 + log10(dp[0]);
        for(int i = 1; i <= 8 - l; ++i) {
            cout << '0';
        }
        cout << dp[0] << "\n";
    }
    return 0;
}