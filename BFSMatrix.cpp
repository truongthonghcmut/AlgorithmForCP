#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const ll mod = 1000000007;
const ld eps = 1e-9;
const ll mxN = 1e3;
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>
#define sll set<ll>
ll row = 5, col = 10, temp = 0;
vector<ll> zone_size;
ll arr[mxN + 5][mxN + 5] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1},
    {0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1}
};
// Direction, if you want diagonal traverse then add more
ll x[4] = {-1, 0, 0, 1};
ll y[4] = {0, -1, 1, 0};
bool c[mxN + 5][mxN + 5];

// Check if the cell is valid and it is not be traversed
bool check(ll x, ll y) {
    if(x > row || x < 1 || y > col || y < 1 || c[x][y]) return 0;
    return 1;
}

void bfs_matrix(ll i, ll j) {
    c[i][j] = 1;
    for(ll z = 0; z <= 3; z++) {
        ll u = i + x[z];
        ll v = j + y[z];
        if(check(u, v) && arr[u][v] == 1) {
            c[u][v] = 1;
            temp++;
            bfs_matrix(u, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    memset(c, false, sizeof(c));

    for(ll i = 1; i <= row; i++) {
        for(ll j = 1; j <= col; j++) {
            if(arr[i][j] == 1 && c[i][j] == false) {
                cout << "Starting find at " << i << " " << j << "\n";
                temp = 1;
                bfs_matrix(i, j);
                zone_size.push_back(temp);
            }
        }
    }
    
    cout << "Number of zone = " << zone_size.size() << "\n";
    for(ll it: zone_size) cout << it << " ";

    return 0;
}