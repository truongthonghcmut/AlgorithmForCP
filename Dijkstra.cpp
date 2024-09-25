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
const int vertices = 10;
vector<pll> adj[11];
void dijkstra(ll source) {
    vector<ll> distance(vertices + 1, inf);
    distance[source] = 0;
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push(make_pair(0, source));
    while(!pq.empty()) {
        pll t = pq.top();
        pq.pop();
        ll len = t.first, u = t.second;
        if(distance[u] < len) continue;
        for(pll p : adj[u]) {
            ll v = p.first, w = p.second;
            if(distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
    for(int i = 1; i <= vertices; i++) cout << "From " << source << " to " << i << " = " << distance[i] << "\n";
    return;
}

int main() {
    // Dijkstra's Algorithm: find the minimum path weight from one vertex to all other vertices
    // For each edge u, v, w: there is one-way direction from u to v with weight w;  --  adj[u].push_back({v, w})
    adj[1].push_back({2, 4});
    adj[1].push_back({3, 2});
    adj[1].push_back({4, 9});
    adj[2].push_back({3, 3});
    adj[2].push_back({7, 8});
    adj[3].push_back({5, 7});
    adj[4].push_back({6, 1});
    adj[5].push_back({6, 1});
    adj[5].push_back({8, 3});
    adj[6].push_back({9, 6});
    adj[7].push_back({10, 6});
    adj[8].push_back({10, 8});
    adj[9].push_back({10, 2});

    dijkstra(1);

    return 0;
}