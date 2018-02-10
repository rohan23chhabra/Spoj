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
const int N = 10000002;

ll power(ll a, ll n, ll m) {
    if (n == 0) {
        return 1;
    }
    ll p = power(a, n / 2, m) % m;
    p *= p;
    p %= m;
    if (n & 1) {
        p = (p * a) % m;
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

int lpd[N];
vector <int> primes;
void sieve() {
    lpd[0] = lpd[1] = 1;
    for (int i = 2; i < N; ++i) {
        if(!lpd[i]) {
            for(int j = i * 2; j < N; j += i) {
                if(!lpd[j])
                    lpd[j] = i;
            }
        }
    }

    for(int i = 2; i < N; i++) {
        if(!lpd[i]) {
            lpd[i] = i;
            primes.pb(i);
        }
    }
}

struct comp_pair_int {
    bool operator()(const pair<int, int> &a, const int & b)
    {
        return (a.first < b);
    }
    bool operator()(const int & a, const pair<int, int> &b)
    {
        return (a < b.first);
    }
};

int cnt[N], times[N];
vector <ii> v[N];
typedef vector <ii> :: iterator vit;
int main() {

    boostIO();
    sieve();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for(int j = 0; j < m; ++j) {
            int a;
            cin >> a;
            while(a > 1) {

                int factor = lpd[a];
                vit it = lower_bound(v[i].begin(), v[i].end(), factor, comp_pair_int());
                if (it == v[i].end()) { 
                    v[i].pb(mp(factor, 1));
                } else {
                    int j = it - v[i].begin();
                    ++v[i][j].S;
                }
                a /= lpd[a];
            }
        }
    }

    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << "(" << v[i][j].F << "," << v[i][j].S << ") ";
        }
        cout << "\n";
    }*/

    for(int j = 0; j < v[0].size(); j++) {
        int factor = v[0][j].F;
        cnt[factor] = v[0][j].S;
        times[factor]++;
    }


    for(int i = 1; i < n; i++) {
        for(int j = 0; j < v[i].size(); j++) {
            int factor = v[i][j].F;
            times[factor]++;
            cnt[factor] = min(cnt[factor], v[i][j].S);
        }
    }

    ll ans = 1;
    for(int j = 0; j < primes.size(); j++) {
        int i = primes[j];
        if(times[i] == n) {
            ans *= power(i, cnt[i], mod);
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}