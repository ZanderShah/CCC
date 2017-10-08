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

int n, x, y, ans = 0;
set<pii> s;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        s.insert(mp(x, y));
    }
    for (auto it = s.begin(); it != s.end(); it++) {
        x = it->x;
        y = it->y;

        if (s.find(mp(x, y + 2018)) != s.end()) {
            ans++;
        }
        if (s.find(mp(x + 1118, y + 1680)) != s.end()) {
            ans++;
        }
        if (s.find(mp(x + 1680, y + 1118)) != s.end()) {
            ans++;
        }
        if (s.find(mp(x + 1118, y - 1680)) != s.end()) {
            ans++;
        }
        if (s.find(mp(x + 1680, y - 1118)) != s.end()) {
            ans++;
        }
        if (s.find(mp(x + 2018, y)) != s.end()) {
            ans++;
        }
    }
    printf("%d\n", ans);
}
