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

int R, C, Q, x, y;
char g;
bool r[1005], c[1005];

int main() {
    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            scanf(" %c", &g);
            if (g == 'X') {
                r[i] = 1;
                c[j] = 1;
            }
        }
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &x, &y);
        printf("%c\n", r[y] || c[x] ? 'Y' : 'N');
    }
}
