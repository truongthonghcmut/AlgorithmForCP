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
bool visited[mxN + 5];
vll adj_bfs[mxN + 5], linked_bfs[mxN + 5];
ll number_connected_components = 0, num_of_vertices = 10;
queue<ll> q;

// Breadth First Search count the number of connected components

void bfs_graph(ll source) {
    q.push(source);
    visited[source] = 1;
    linked_bfs[number_connected_components].push_back(source);
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        for(ll i = 0; i < (ll)adj_bfs[u].size(); i++) {
            if(visited[adj_bfs[u][i]] == false) {
                visited[adj_bfs[u][i]] = true;
                linked_bfs[number_connected_components].push_back(adj_bfs[u][i]);
                q.push(adj_bfs[u][i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(visited, false, sizeof(visited));
    
    adj_bfs[1].push_back(2);
    adj_bfs[2].push_back(1);
    adj_bfs[2].push_back(6);
    adj_bfs[6].push_back(2);
    adj_bfs[2].push_back(8);
    adj_bfs[8].push_back(2);
    adj_bfs[4].push_back(3);
    adj_bfs[3].push_back(4);
    adj_bfs[3].push_back(7);
    adj_bfs[7].push_back(3);
    adj_bfs[4].push_back(7);
    adj_bfs[7].push_back(3);

    for(ll i = 1; i <= num_of_vertices; i++) {
        if(visited[i] == false) {
            number_connected_components++;
            bfs_graph(i);
        }
    }
    cout << "Number of connected components using BFS: " << number_connected_components << "\n";
    for(ll i = 1; i <= number_connected_components; i++) {
        sort(linked_bfs[i].begin(), linked_bfs[i].end());
        for(ll it: linked_bfs[i]) cout << it << " ";
        cout << "\n";
    }

    return 0;
}