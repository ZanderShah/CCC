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

pii rr[3], r[3];

bool valid(int i, int x, int y) {
    if (3 <= i) {
        return x == y;
    }
    bool ret = 0;
    if (r[i].x == x) {
        ret |= valid(i + 1, x, y + r[i].y);
    }
    if (r[i].y == x) {
        ret |= valid(i + 1, x, y + r[i].x);
    }
    if (r[i].x == y) {
        ret |= valid(i + 1, x + r[i].y, y);
    }
    if (r[i].y == y) {
        ret |= valid(i + 1, x + r[i].x, y);
    }
    return ret;
}

int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &rr[i].x, &rr[i].y);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i == j || i == k || j == k) continue;
                r[0] = rr[i];
                r[1] = rr[j];
                r[2] = rr[k];
                if (valid(1, r[0].x, r[0].y) || valid(1, r[0].y, r[0].x)) {
                    printf("YES\n");
                    return 0;
                }
            }
        }
    }
    printf("NO\n");
}
