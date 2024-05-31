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

// DSU - Disjoint Set Union
/*
    From a graph with n vertices and no edges, do one of the operation:
    - Add a edge (x, y);
    - Check if vertices x and y belong to one connected components
*/

// Parent, size, max, min, sum of each set, value[v] is the value of element at index v
ll parent[mxN + 5], sz[mxN + 5], sum[mxN + 5], mx[mxN + 5], mn[mxN + 5], value[mxN + 5];

void makeSet(ll v) {
    parent[v] = v;
    sz[v] = 1;
    mn[v] = value[v];
    mx[v] = value[v];
    sum[v] = value[v];
}

ll findSet(ll v) {
    if(v == parent[v]) return v;
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
        sum[a] += sum[b];
        mn[a] = min(mn[a], mn[b]);
        mx[a] = max(mx[a], mx[b]);
    }
}

ll findSum(ll v) {
    v = findSet(v);
    return sum[v];
}

ll findMin(ll v) {
    v = findSet(v);
    return mn[v];
}

ll findMax(ll v) {
    v = findSet(v);
    return mx[v];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    memset(sz, 0, sizeof(sz));
    ll number_vertice = 10;
    
    for(ll i = 1; i <= number_vertice; i++) value[i] = 11 - i;
    for(ll i = 1; i <= number_vertice; i++) makeSet(i);
    
    unionSet(1, 3);
    unionSet(3, 6);
    unionSet(3, 8);
    unionSet(2, 4);
    unionSet(4, 7);
    unionSet(5, 9);
    unionSet(5, 10);

    cout << "Vertex 1 and 8 are " << (findSet(1) == findSet(8) ? "connected.\n" : "disconnected.\n");
    cout << "Vertex 2 and 10 are " << (findSet(2) == findSet(10) ? "connected.\n" : "disconnected.\n");

    cout << "Sum of value of graph that has vertex 6 is: " << findSum(6) << "\n";
    cout << "Minimum value of graph that has vertex 2 is: " << findMin(2) << "\n";
    cout << "Maximum value of graph that has vertex 10 is: " << findMax(10) << "\n";

    return 0;
}