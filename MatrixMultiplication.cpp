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

// Find n'th Fibonacci number % mod using matrix multiplication 

struct matrix {
    ll val[3][3];
    matrix() {
        for(ll i = 0; i <= 2; i++) {
            for(ll j = 0; j <= 2; j++) {
                val[i][j] = 0;
            }
        }
    }
};

matrix multiply(matrix a, matrix b) {
    matrix c;
    for(ll i = 1; i <= 2; i++) {
        for(ll j = 1; j <= 2; j++) {
            for(ll k = 1; k <= 2; k++) {
                c.val[i][j] += (ll)(a.val[i][k] * b.val[k][j]) % mod;
            }
        }
    }
    return c;
}
matrix power(matrix a, ll k) {
    matrix res;
    if(k == 1) return a;
    res = power(a, k/2);
    res = multiply(res, res);
    if(k % 2 == 1) res = multiply(res, a);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    matrix f;
    f.val[1][1] = 1;
    f.val[1][2] = 1;
    f.val[2][1] = 1;
    f.val[2][2] = 0;
    for(ll i = 0; i <= mxN; i++) {
        if(i == 0) cout << "0 - 0 ";
        if(i == 1) cout << "1 - 1 ";
        if(i >= 2) {
            matrix temp = power(f, i - 1);
            cout << i <<  " - " << temp.val[1][1] % mod << " ";
        } 
    }

    return 0;
}