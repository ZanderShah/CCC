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
 
int N, M, m[1001], t[1001], x, y, len, dp[1001][5001];
vector<pii> pts;

int ccw (pii p1, pii p2, pii p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}
double convex () {
    vector<pii> u, l;
    sort(pts.begin(), pts.end());
    for (int i = 0; i < pts.size(); i++) {
        int j = l.size();
        while (j >= 2 && ccw(l[j - 2], l[j - 1], pts[i]) <= 0) {
            l.pop_back();
            j = l.size();
        }
        l.pb(pts[i]);
    }
    for (int i = pts.size() - 1; i >= 0; i--) {
        int j = u.size();
        while (j >= 2 && ccw(u[j - 2], u[j - 1], pts[i]) <= 0) {
            u.pop_back();
            j = u.size();
        }
        u.pb(pts[i]);
    }
    l.pop_back();
    u.pop_back();
    l.reserve(l.size() + u.size());
    l.insert(l.end(), u.begin(), u.end());
    double ans = 0;
    for (int i = 0; i < l.size(); i++) {
        ans += sqrt((l[i].x - l[(i + l.size() - 1) % l.size()].x) * (l[i].x - l[(i + l.size() - 1) % l.size()].x) + (l[i].y - l[(i + l.size() - 1) % l.size()].y) * (l[i].y - l[(i + l.size() - 1) % l.size()].y));
    }
    return ans;
}

int go(int i, int j) {
    if (j <= 0) {
        return 0;
    }
    if (i >= N) {
        return 1 << 30;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ret = 1 << 30;
    ret = min(ret, go(i + 1, j));
    ret = min(ret, go(i + 1, j - m[i]) + t[i]);
    return dp[i][j] = ret;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &m[i], &t[i]);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        pts.pb(mp(x, y));
    }
    len = ceil(convex());
    memset(dp, -1, sizeof dp);
    printf("%d\n", go(0, len));
}
