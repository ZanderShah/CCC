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

const int MAXN = 1e5 + 5;

int N, ans = 2 * MAXN;
pii A[MAXN], B[MAXN];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i].x);
        A[i].y = i;
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i].x);
        B[i].y = i;
    }
    sort(A, A + N);
    sort(B, B + N);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (A[i].y != B[j].y) {
                ans = min(ans, A[i].x + B[j].x);
            }
        }
    }
    printf("%d\n", ans);
}
