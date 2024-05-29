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
vll adj_dfs[mxN + 5], linked_dfs[mxN + 5];
ll number_connected_components = 0;
ll num_of_vertices = 10;
// DFS - Count the number of connecting components of a graph

void dfs_graph(ll source) {
    visited[source] = 1;
    linked_dfs[number_connected_components].push_back(source);
    for(ll i = 0; i < (ll)adj_dfs[source].size(); i++) {
        if(visited[adj_dfs[source][i]] == 0) {
            dfs_graph(adj_dfs[source][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    memset(visited, 0, sizeof(visited));

    adj_dfs[1].push_back(2);
    adj_dfs[2].push_back(1);
    adj_dfs[2].push_back(5);
    adj_dfs[5].push_back(2);
    adj_dfs[1].push_back(5);
    adj_dfs[5].push_back(1);
    adj_dfs[5].push_back(6);
    adj_dfs[6].push_back(5);
    adj_dfs[3].push_back(4);
    adj_dfs[4].push_back(3);
    adj_dfs[3].push_back(8);
    adj_dfs[8].push_back(3);
    adj_dfs[2].push_back(9);
    adj_dfs[9].push_back(2);
    for(ll i = 1; i <= num_of_vertices; i++) {
        if(visited[i] == false) {
            number_connected_components++;
            dfs_graph(i);
        }
    }
    cout << "Number of connected components using DFS: " << number_connected_components << "\n";
    for(ll i = 1; i <= number_connected_components; i++) {
        sort(linked_dfs[i].begin(), linked_dfs[i].end());
        for(ll it: linked_dfs[i]) cout << it << " ";
        cout << "\n";
    }

    return 0;
}