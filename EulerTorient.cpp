#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const ll mod = 1000000007;
const ld eps = 1e-9;
const ll mxN = 1e6;
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>
#define sll set<ll>

ll phi[mxN + 5];

ll phiEuler(ll n) {
    if(n <= 1) return n;
    ll res = n;
    for(ll i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                n = n / i;
            }
            res = res - (res / i);
        }
    }
    if(n > 1) res = res - (res / n);
    return res;
}

// Find all Torient Euler from 1 to n
void phiSieve() {
    for(ll i = 0; i <= mxN; i++) phi[i] = i;
    for(ll i = 2; i <= mxN; i++) {
        if(phi[i] == i) {
            for(ll j = i; j <= mxN; j += i) {
                phi[j] = phi[j] - phi[j] / i;
            } 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    memset(phi, 0, sizeof(phi));
    phiSieve();
    cout << "Euler Torient from 0 to 1e6: ";
    for(ll i = 0; i <= mxN; i++) cout << i << " - " << phi[i] << " ";
    return 0;
}