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
ll f[mxN + 5]; 
ll rev_f[mxN + 5];
// About Modular Inverse: a^-1 is a modular inverse of a mod m if a * a ^ (-1) - 1 divisible by m
// a^ (-1) exist if gcd(a, m) = 1
/*
    - When gcd(a, m) = 1:
    + If m is a prime number, a^(m - 2) congruent a^(-1)
    + If m is any number, a^(phi(m) - 1) congruent a^(-1) -> using binary exponent
*/

ll power(ll n, ll k) {
    if(k == 0) return 1 % mod;
    if(k == 1) return n % mod;
    ll ans = power(n, k/2) % mod;
    ans = (ans * ans) % mod;
    if(k % 2 == 1) ans = (ans * n) % mod;
    return ans; 
}

// Calculate nCk % mod with mod is a prime number (usually 1e7 or 998244353)
void factorialModularInverse() {
    f[0] = 1;
    for(ll i = 1; i <= mxN; i++) {
        f[i] = ((i % mod) * (f[i - 1] % mod)) % mod;
    }
    rev_f[mxN] = power(f[mxN], mod - 2);
    for(ll i = mxN - 1; i >= 0; i--) {
        rev_f[i] = (((i + 1) % mod) * (rev_f[i + 1] % mod)) % mod;
    }
}

// Combinatoric nCk = n! / (k! * (n - k)!)
ll combinatoric(ll n, ll k) {
    if(k > n) throw "Invalid";
    return ((((f[n] % mod) * (rev_f[k] % mod)) % mod) * (rev_f[n - k] % mod)) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(f, 0, sizeof(f));
    memset(rev_f, 0, sizeof(rev_f));
    factorialModularInverse();
    cout << combinatoric(100, 5);
    return 0;
}