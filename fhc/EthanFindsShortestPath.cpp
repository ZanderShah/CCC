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

struct Edge {
    int u, v, w;
};

int T, N, K, s;
vector<Edge> e;

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d %d", &N, &K);
        s = 0;

        e.clear();
        for (int k = K - 1, n = 1; n < N && k >= 1; --k, ++n) {
            if (k == 1 && n + 1 != N) {
                e.push_back(Edge{n, N, k});
            } else {
                e.push_back(Edge{n, n + 1, k});
            }
            s += k;
        }
        if (e.size() != 1) {
            e.push_back(Edge{1, N, K});
        }

        printf("Case #%d: %d\n", t, max(0, s - K));
        printf("%d\n", e.size());
        for (Edge ee : e) {
            printf("%d %d %d\n", ee.u, ee.v, ee.w);
        }
    }
}
