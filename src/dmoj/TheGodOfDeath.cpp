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

const int MAXN = 1e6 + 5;
int N, Q, x, y, d = 0;
char c;
vector<pii> v[MAXN];

int query(int x, int y) {
    for (int i = 0; i < v[x].size(); i++) {
        if (v[x][i].x > y) {
            return v[x][i - 1].y;
        }
    }
    return v[x].back().y;
    // int l = 0, h = v[x].size() - 1, m = (l + h) / 2;
    // while (l < h) {
    //     if (v[x][m].x < y) {
    //         l = m + 1;
    //     } else {
    //         h = m - 1;
    //     }
    //     m = (l + h) / 2;
    // }
    // return v[x][l].y;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &x);
        v[i].pb(mp(0, x));
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf(" %c %d %d", &c, &x, &y);
        if (c == 'C') {
            v[x].pb(mp(++d, y));
        } else {
            printf("%d\n", query(x, y));
        }
    }
}
