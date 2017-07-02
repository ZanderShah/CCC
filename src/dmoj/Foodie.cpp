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
#include <cassert>

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

int C, N, v;
bool dp[1000005];

int main() {
    scanf("%d %d", &C, &N); 
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        scan(v); 
        for (int j = C - 1; j >= v; j--) {
            dp[j] |= dp[j - v];
        }
    }
    for (int i = C - 1; i >= 0; i--) {
        if (dp[i]) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("0\n");
}