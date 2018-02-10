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

inline ll power(ll a, ll n) {
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

map <string, int> m;
string s1, s2, s3;
int P, M;

int solve (int **dp, int i, int j) {

    if (i == -1 && j == -1) // both strings consumed.
        return 1;
    if (i == -1) //pattern consumed.
        return 1;
    if (j == -1)//only first string consumed.
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        dp[i][j] = solve(dp, i - 1, j - 1) + solve(dp, i, j - 1);
    else
        dp[i][j] = solve(dp, i, j - 1);

    return dp[i][j];
}

void toLower(string &s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] += 32;
    }
}

int main() {

    boostIO();

    while (true) {

        int n;
        m.clear();

        cin >> n;

        if(n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            m[s] = 1;
        }

        
        while (true) {

            s1.clear();
            s2.clear();
            s3.clear();
            char ar[209];
            scanf("%[^\n]s", ar);
            string s(ar);

            if (s == "LAST CASE") {
                break;
            }

            int i;
            for (i = 0; i < s.length(); i++) {

                if (s[i] == ' ') {
                    break;
                } 
                else {
                    s1.pb(s[i]);
                }
            }

            for (i++; i < s.length(); i++) {

                if(s[i] == ' ') {

                    if(m[s3]) {
                        s3.clear();
                    }
                    s2 += s3;
                    s3.clear();
                } 
                else {
                    s3.pb(s[i]);
                }
            }

            s2 += s3;


            // s1 and s2 prepared.
            P = s1.length();
            M = s2.length();

            int **dp = new int*[s1.length() + 5];
            for (int i = 0; i < s1.length() + 5; i++) {
                dp[i] = new int[s2.length() + 5];
            }

            for (int i = 0; i < P + 5; i++) {
                for(int j = 0; j < M + 5; j++) {
                    dp[i][j] = -1;
                }
                //cout << "\n";
            }

            for (int i = 0; i < P + 5; i++) {
                for(int j = 0; j < M + 5; j++) {
                    cout << dp[i][j] << " ";
                }
                cout << "\n";
            }

            toLower(s1);

            cout << "pattern = " << s1 << "\n";
            cout << "string  = " << s2 << "\n";


            cout << s1 << " can be formed in ";
            cout << solve(dp, s1.length() - 1, s2.length() - 1) << " ways\n";
        }
    }
    int x;
    cin >> x;
    return 0;
}