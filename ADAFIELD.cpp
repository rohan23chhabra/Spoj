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

typedef multiset<ll>::iterator SI;

int main() {

    boostIO();
    int t;
    cin >> t;
    while(t--) {
        ll n, m, q;
        cin >> n >> m >> q;
        multiset <ll> x, y, xd, yd;
        x.insert(0);
        x.insert(n);
        y.insert(0);
        y.insert(m);
        xd.insert(n);
        yd.insert(m);
        while(q--) {
            int type, a;
            cin >> type >> a;
            if(type) //y - coordinate
            {
                if(y.find(a) == y.end()) {
                    SI high = y.upper_bound(a);
                    SI low = --high;
                    high++;
                    SI del = yd.find(*high - *low);
                    yd.erase(del);
                    yd.insert(a - *low);
                    yd.insert(*high - a);
                    y.insert(a);
                }
            } 
            else //x - coordinate
            {
                if(x.find(a) == x.end()) {
                    SI high = x.upper_bound(a);
                    SI low = --high;
                    high++;
                    SI del = xd.find(*high - *low);
                    xd.erase(del);
                    xd.insert(a - *low);
                    xd.insert(*high - a);
                    x.insert(a);
                }
            }
            SI it1 = xd.end();
            it1--;
            SI it2 = yd.end();
            it2--;
            cout << (*it1) * (*it2) << "\n";  
        }
    }
    return 0;
}