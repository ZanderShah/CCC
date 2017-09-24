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

int A, B, C, D, E, F, w, s;

int main() {
    scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);
    // Go through every possible starting value of water
    for (int a = 0; a <= F; a += A * 100) {
        for (int b = 0; a + b <= F; b += B * 100) {
            for (int c = 0; a + b + c <= F; c += C) {
                for (int d = 0; a + b + c + d <= F; d += D) {
                    // Check if sugar can dissolve in beaker
                    if (a == 0 && b == 0) continue;
                    if ((c + d) * 100 > (a + b) * E) continue;
                    if (w == 0 || s * 1.0 / (w + s) < (c + d) * 1.0 / (a + b + c + d)) {
                        w = a + b;
                        s = c + d;
                    }
                }
            }
        }
    }
    printf("%d %d\n", w + s, s);
}
