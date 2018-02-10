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
map <ll, int> cnt;
int main() {

    boostIO();
    ll n, ar[102];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> ar[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ll prod = ar[i] * ar[j];
            for(int k = 0; k < n; k++) {
                cnt[prod + ar[k]]++;
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(ar[k]) {
                    ans += cnt[ar[k] * (ar[i] + ar[j])];
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}