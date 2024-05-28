#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 1e6;
bool check[maxN + 5];
ll lpf[maxN + 5];
vector<ll> prime_era;
vector<ll> prime_lpf;

// Eratosthenes Sieve
void eratosthenes() {
    check[0] = 1;
    check[1] = 1;
    for(ll i = 2; i <= maxN; i++) {
        if(check[i] == 0) {
            prime_era.push_back(i);
            for(ll j = i; j <= maxN / i; j++) check[i * j] = 1;
        }
    }
}

// Lowest prime factor of a number - Linear Sieve
void linearSieve() {
    for(ll i = 2; i <= sqrt(maxN); i++) {
        if(lpf[i] == 0) {
            lpf[i] = i;
            prime_lpf.push_back(i);
            for(ll j = i; j <= maxN / i; j++) {
                if(lpf[i * j] == 0) lpf[i * j] = i;
            }
        }
    }
    for(ll i = sqrt(maxN) + 1; i <= maxN; i++) {
        if(lpf[i] == 0) {
            prime_lpf.push_back(i);
            lpf[i] = i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(check, false, sizeof(check));
    memset(lpf, 0, sizeof(lpf));
    eratosthenes();
    cout << "Prime numbers from 2 to 1e6 using Eratosthene Sieve: ";
    for(ll it: prime_era) cout << it << " ";
    cout << "\n";
    linearSieve();
    cout << "Prime numbers from 2 to 1e6 using Linear Sieve: ";
    for(ll it: prime_lpf) cout << it << " ";
    cout << "\n";
    cout << "Number from 2 to 1e6 and its lowest prime number: ";
    for(ll i = 2; i <= maxN; i++) {
        cout << i << " - " << lpf[i] << " ";
    }
    return 0;
}