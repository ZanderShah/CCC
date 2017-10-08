#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <deque>
#include <unordered_map>
#include <map>
#include <bitset>
#include <string>
#include <cstring>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do {while((x=getchar())<'0') ; for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0') ; } while(0)
char _;
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;

struct Seg {
    ll x, y;
    bool operator< (const Seg& s) const {
        return x == s.x ? y < s.y : x < s.x;
    }
};

int n, k;
ll m[10005], b[10005], e[10005], t1, t2, bad = 0, x;
Seg s;
vector<Seg> seg;
stack<Seg> stk;

// [a, b] & [c, d]
Seg intersect(ll a, ll b, ll c, ll d) {
    if (min(b, d) <= max(a, c)) {
        return Seg{t1, t1};
    } 
    return Seg{max(a, c), min(b, d)};
}

int main() {
    scanf("%d %d %lld %lld", &n, &k, &t1, &t2);
    // need good area for t + m
    for (int i = 0; i < n; i++) {
        scanf("%lld", &m[i]);
    }
    // [b, e] bad area
    for (int i = 0; i < k; i++) {
        scanf("%lld %lld", &b[i], &e[i]);
    }

    for (int i = 0; i < n; i++) {
        // Segment [t1 + m[i], t2 + m[i]]
        for (int j = 0; j < k; j++) {
            // Check intersection with bad area
            // If intersection is between [x, y] then cannot start between [x - m[i], y - m[i]]
            s = intersect(t1 + m[i], t2 + m[i], b[j], e[j]);
            s = Seg{max(s.x - m[i], t1), min(s.y - m[i], t2)};
            if (s.x < s.y) {
                seg.pb(s);
            }
        }
    }

    sort(seg.begin(), seg.end());
    for (int i = 0; i < seg.size(); i++) {
        if (stk.empty() || stk.top().y < seg[i].x) {
            stk.push(seg[i]);
        } else if (stk.top().y < seg[i].y) {
            seg[i].x = stk.top().x;
            stk.pop();
            stk.push(seg[i]);
        }
    }
    while (!stk.empty()) {
        bad += stk.top().y - stk.top().x;
        stk.pop();
    }

    printf("%.9lf\n", 1 - bad * 1.0 / (t2 - t1));
}
