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
int n, g = 0, r = 0, m = -1;
bool A[MAXN], B[MAXN];

int main() {
    scan(n);
    for (int i = 0, x; i < n; i++) {
        scan(x);
        A[x] = 1;
        m = max(m, x);
    }
    for (int i = 0, x; i < n; i++) {
        scan(x);
        B[x] = 1;
        m = max(m, x);
    }

    for (int i = m; i >= 1; i--) {
        int a = 0, b = 0;
        for (int j = i; j <= m; j += i) {
            if (A[j]) {
                a = j;
            } 
            if (B[j]) {
                b = j;
            }
        }
        if (a && b) {
            printf("%d\n", a + b);
            return 0;
        }
    }
}
