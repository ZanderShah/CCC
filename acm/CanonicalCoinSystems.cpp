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

int n, c[105], dp[2000005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < c[n - 2] + c[n - 1]; i++) {
        dp[i] = 0;
        for (int j = i, k = n - 1; j != 0; k--) {
            dp[i] += j / c[k];
            j = j % c[k];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = c[i]; j < c[n - 2] + c[n - 1]; j++) {
            if (dp[j - c[i]] + 1 < dp[j]) {
                printf("non-canonical\n");
                return 0;
            }
        }
    }
    printf("canonical\n");
}
