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

int N, f, c = 0;
bool p[100005];

int main() {
    scanf("%d", &N);
    p[1] = 1;
    for (int i = 2; i <= 1e5; i++) {
        if (p[i]) continue;
        for (int j = 2 * i; j <= 1e5; j += i) p[j] = 1;
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &f);
        c += !p[f];
    }
    printf("%d\n", c);
}
