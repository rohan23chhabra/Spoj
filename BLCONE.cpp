#include <bits/stdc++.h> 
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
typedef pair < int, int > ii;
typedef pair < int, pair < int, int > > iii;
typedef long long ll;
const int mod = 1000000007;
const long double eps = 0.000005;
const long double pi = 3.141592653589793;
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

int main() {

    boostIO();
    int t;
    cin >> t;
    while(t--)
    {
        int R, H;
        cin >> R >> H;
        long double L = sqrt(R * R + H * H);
        long double low = 0.0, high = 200.0;
        while(high - low > eps) {
            long double h, r, l, ca, v, ua;
            h = low + (high - low) / 2;
            cout << h << "\n";
            r = (h / H) * R;
            l = sqrt(r * r + h * h);
            ca = r * l;
            v = (r * r * h) / 3.0;
            ua = R * L - ca;
            if(v - ua < eps) {
                low = h;
                break;
            }
            if(v < ua){
                low = h;
            } else {
                high = h;
            }
        }
        printf("%.6f\n", low);
    }
    return 0;
}