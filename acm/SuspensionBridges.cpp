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

const double EPS = 1e-9;
int d, s;

int main() {
    scanf("%d %d", &d, &s);
    double lo = 1e-9, hi = 1e9, mid = (lo + hi) / 2;
    while (hi - lo > EPS) {
        double ss = mid / 2 * (exp(d / mid / 2) + exp(-d / mid / 2)) - mid;
        if (ss < s) {
            hi = mid - EPS;
        } else {
            lo = mid + EPS;
        }
        mid = (lo + hi) / 2;
    }
    printf("%.9lf", lo * (exp(d / lo / 2) - exp(-d / lo / 2)));
}
