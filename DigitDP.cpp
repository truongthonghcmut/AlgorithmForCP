#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const ll mod = 1000000007;
const ld eps = 1e-9;
const ll mxN = 1e5;
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>
#define sll set<ll>

// Count in [a, b] how many number has GCD of sum of all digit and sum of square of all digit is 1
// [100, 150] -> 19

ll temp = 0, digit[20], dp[20][172][1540][2];

ll gcd(ll x, ll y) {
    while(y != 0) {
        ll d = x % y;
        x = y;
        y = d;
    }
    return x;
}

void analyze(ll n) {
    memset(dp, -1, sizeof(dp));
    temp = 0;
    while(n > 0) {
        digit[++temp] = n % 10;
        n = n / 10;
    }
    reverse(digit + 1, digit + temp + 1);
}

ll calculate(ll n, ll s1, ll s2, bool smaller) {
    if(n > temp) return gcd(s1, s2) == 1;
    if(dp[n][s1][s2][smaller] != -1) return dp[n][s1][s2][smaller];
    ll least = (smaller == true) ? 9 : digit[n];
    ll res = 0;
    for(ll i = 0; i <= least; i++) {
        bool checksmall = (smaller || i < least);
        res = res + calculate(n + 1, s1 + i, s2 + i * i, checksmall);
    }
    return dp[n][s1][s2][smaller] = res;
}

ll solve(ll n) {
    analyze(n);
    return calculate(1, 0, 0, false);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll l = 1, r = 1e18;
    cout << solve(r) - solve(l - 1);

    return 0;
}