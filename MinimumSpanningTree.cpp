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

ll parent[mxN + 5], sz[mxN + 5], res = 0, num_vertices = 10;
vector<vll> edge;

// MST using DSU + Kruskal's Algorithm
void makeSet(ll v) {
    parent[v] = v;
    sz[v] = 1;
}

ll findSet(ll v) {
    if(parent[v] == v) return v;
    ll p = findSet(parent[v]);
    parent[v] = p;
    return p;
}

void unionSet(ll a, ll b) {
    a = findSet(a);
    b = findSet(b);
    if(a != b) {
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

// Kruskal's Algorithm
void kruskalMST() {
    cout << "The minimum spanning tree is formed by: \n";
    // Sort by weight
    sort(edge.begin(), edge.end());
    for(auto e : edge) {
        ll w = e[0];
        ll u = e[1];
        ll v = e[2];
        // Check if u and v are not belong to a connected component
        if(findSet(u) != findSet(v)) {
            res = res + w;
            unionSet(u, v);
            cout << u << " - " << v << " with weight = " << w << "\n"; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for(ll i = 1; i <= 10; i++) makeSet(i);

    // Infomation for each edge: weight - v1 - v2
    edge.push_back({1, 1, 2});
    edge.push_back({2, 2, 3});
    edge.push_back({4, 1, 3});
    edge.push_back({2, 2, 4});
    edge.push_back({2, 2, 5});
    edge.push_back({2, 3, 6});
    edge.push_back({3, 4, 7});
    edge.push_back({6, 4, 9});
    edge.push_back({5, 5, 9});
    edge.push_back({3, 5, 6});
    edge.push_back({1, 6, 8});
    edge.push_back({6, 7, 10});
    edge.push_back({6, 8, 10});
    edge.push_back({4, 9, 10});

    kruskalMST();
    cout << "The weight of minimum spanning tree = " << res << "\n";

    return 0;
}