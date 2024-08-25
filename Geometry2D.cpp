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

struct point2d
{
    ld x, y;
    point2d() {
        x = 0;
        y = 0;
    }
    point2d(ld x, ld y) {
        this->x = x;
        this->y = y;
    }
};

struct vector2d
{
    ld x, y;
    vector2d() {
        x = 0;
        y = 0;
    }
    vector2d(ld x, ld y) {
        this->x = x;
        this->y = y;
    }
    vector2d(point2d a) {
        this->x = a.x;
        this->y = a.y;
    }
    vector2d(point2d a, point2d b) {
        this->x = b.x - a.x;
        this->y = b.y - a.y;
    }
};

ld dot_proc(vector2d a, vector2d b) {return a.x * b.x + a.y * b.y;}
ld norm(vector2d a) {return dot_proc(a, a);}
ld vector_len(vector2d a) {return sqrt(norm(a));}
ld projection(vector2d a, vector2d b) {return dot_proc(a, b) / vector_len(b);}
ld angle(vector2d a, vector2d b) {return acos(dot_proc(a, b) / vector_len(a) / vector_len(b));}

ld segment_len(point2d a, point2d b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

ld triangle_area(point2d a, point2d b, point2d c) {
    ld ab = segment_len(a, b);
    ld bc = segment_len(b, c);
    ld ca = segment_len(c, a);
    ld p = (ab + bc + ca) / 2;
    return sqrt(p * (p - ab) * (p - bc) * (p - ca));
}

ld circumradius(point2d a, point2d b, point2d c) {
    ld ab = segment_len(a, b);
    ld bc = segment_len(b, c);
    ld ca = segment_len(c, a);
    ld area = triangle_area(a, b, c);
    return ab * bc * ca / 4 / area;
}

ld inradius(point2d a, point2d b, point2d c) {
    ld ab = segment_len(a, b);
    ld bc = segment_len(b, c);
    ld ca = segment_len(c, a);
    ld p = (ab + bc + ca) / 2;
    ld area = triangle_area(a, b, c);
    return area / p;
}

ld median_at_first(point2d a, point2d b, point2d c) {
    ld ab = segment_len(a, b);
    ld bc = segment_len(b, c);
    ld ca = segment_len(c, a);
    return sqrt(2 * (ab * ab + ca * ca) - bc * bc) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    point2d o(0, 0), p1(9, 2), p2(2, 2), p3(4, 7);
    vector2d v1(p1), v2(p2, p3);
    cout << vector_len(v1) << "\n";
    cout << vector_len(v2) << "\n";
    cout << angle(v1, v2) << "\n";
    cout << projection(v1, v2) << "\n";

    cout << triangle_area(p1, p2, p3) << "\n";
    cout << circumradius(p1, p2, p3) << "\n";
    cout << inradius(p1, p2, p3) << "\n";

    return 0;
}
