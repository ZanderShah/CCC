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

int N;
ll x[10][10], y;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &x[0][i]);
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            x[i][j] = x[i - 1][j + 1] - x[i - 1][j];
        }
        bool d = 1;
        for (int j = 1; j < N - i; j++) {
            d &= x[i][0] == x[i][j];
        }
        if (d) {
            printf("%d ", i);
            for (int j = 0; i - j >= 0; j++) {
                y += x[i - j][N - i - 1 + j];
            }
            printf("%lld\n", y);
            return 0;
        }
    }

}
