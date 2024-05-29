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

// Segment Tree - query of min / max / sum of array from index [l, r] which have update:
// + Update arr[index] = val
// + Increase / decrease value of [bn; ed] by value val
// 1: min | 2 : max | 3 : sum

ll arr[] = {0, 10, 20, 40, 60, 70, 150, 30, 80, 25, 210, 330, 20, 80, 60, 100};
ll st[4 * mxN + 5][4], lazy[4 * mxN];

void buildSegmentTree(ll id, ll l, ll r) {
    if(l == r) {
        st[id][1] = arr[l];
        st[id][2] = arr[l];
        st[id][3] = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    buildSegmentTree(2 * id, l, mid);
    buildSegmentTree(2 * id + 1, mid + 1, r);
    st[id][1] = min(st[2 * id][1], st[2 * id + 1][1]);
    st[id][2] = max(st[2 * id][2], st[2 * id + 1][2]);
    st[id][3] = st[2 * id][3] + st[2 * id + 1][3];
}

// Lazy Propagation
void lazyUpdate(ll id, ll l, ll r) {
    if(!lazy[id]) return;
    st[id][1] += lazy[id];
    st[id][2] += lazy[id];
    st[id][3] += (r - l + 1) * lazy[id];
    if(l != r) {
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
    }
    lazy[id] = 0;
}

// Increase val from [bn; ed]
void increaseRange(ll id, ll l, ll r, ll bn, ll ed, ll val) {
    lazyUpdate(id, l, r);
    if(l > ed || r < bn) return;
    if(l >= bn && r <= ed) {
        lazy[id] += val;
        lazyUpdate(id, l, r);
        return;
    }
    ll mid = (l + r) / 2;
    increaseRange(2 * id, l, mid, bn, ed, val);
    increaseRange(2 * id + 1, mid + 1, r, bn, ed, val);
    st[id][1] = min(st[2 * id][1], st[2 * id + 1][1]);
    st[id][2] = max(st[2 * id][2], st[2 * id + 1][2]);
    st[id][3] = st[2 * id][3] + st[2 * id + 1][3];
}

// Update arr[index] = val
void changeIndex(ll id, ll l, ll r, ll index, ll val) {
    lazyUpdate(id, l, r);
    if(index < l || index > r) return;
    if(l == r) {
        st[id][1] = val;
        st[id][2] = val;
        st[id][3] = val;
        return;
    }
    ll mid = (l + r) / 2;
    changeIndex(2 * id, l, mid, index, val);
    changeIndex(2 * id + 1, mid + 1, r, index, val);
    st[id][1] = min(st[2 * id][1], st[2 * id + 1][1]);
    st[id][2] = max(st[2 * id][2], st[2 * id + 1][2]);
    st[id][3] = st[2 * id][3] + st[2 * id + 1][3];
}

// 1: Get min of array from bn to ed
ll getMin(ll id, ll l, ll r, ll bn, ll ed) {
    lazyUpdate(id, l, r);
    if(l > ed || r < bn) return inf;
    if(l >= bn && r <= ed) return st[id][1];
    ll mid = (l + r) / 2;
    ll min1 = getMin(2 * id, l, mid, bn, ed);
    ll min2 = getMin(2 * id + 1, mid + 1, r, bn, ed);
    return min(min1, min2);
}

// 2: Get max of array from bn to ed
ll getMax(ll id, ll l, ll r, ll bn, ll ed) {
    lazyUpdate(id, l, r);
    if(l > ed || r < bn) return -inf;
    if(l >= bn && r <= ed) return st[id][2];
    ll mid = (l + r) / 2;
    ll max1 = getMax(2 * id, l, mid, bn, ed);
    ll max2 = getMax(2 * id + 1, mid + 1, r, bn, ed);
    return max(max1, max2);
}

// 3: Get sum of array from bn to ed
ll getSum(ll id, ll l, ll r, ll bn, ll ed) {
    lazyUpdate(id, l, r);
    if(l > ed || r < bn) return 0;
    if(l >= bn && r <= ed) return st[id][3];
    ll mid = (l + r) / 2;
    ll sum1 = getSum(2 * id, l, mid, bn, ed);
    ll sum2 = getSum(2 * id + 1, mid + 1, r, bn, ed);
    return sum1 + sum2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(st, 0, sizeof(st));
    memset(lazy, 0, sizeof(lazy));

    buildSegmentTree(1, 1, 15);
    cout << "Phase 1:\n";
    cout << getMin(1, 1, 15, 3, 12) << "\n";
    cout << getMax(1, 1, 15, 5, 11) << "\n";
    cout << getSum(1, 1, 15, 6, 10) << "\n";
    
    changeIndex(1, 1, 15, 7, 5);
    changeIndex(1, 1, 15, 8, 400);

    cout << "Phase 2:\n";
    cout << getMin(1, 1, 15, 3, 12) << "\n";
    cout << getMax(1, 1, 15, 5, 11) << "\n";
    cout << getSum(1, 1, 15, 6, 10) << "\n";

    increaseRange(1, 1, 15, 7, 10, 300);

    cout << "Phase 3:\n";
    cout << getMin(1, 1, 15, 3, 12) << "\n";
    cout << getMax(1, 1, 15, 5, 11) << "\n";
    cout << getSum(1, 1, 15, 6, 10) << "\n";

    return 0;
}