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
#include <unordered_set>
#include <map>
#include <bitset>

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
typedef unordered_map<int, int> umii;

int T, P, X, Y;

int main() {
	scanf("%d", &T);
	for (int c = 1; c <= T; c++) {
		scanf("%d %d %d", &P, &X, &Y);

		if (P == 0 || (X - 50) * (X - 50) + (Y - 50) * (Y - 50) > 50 * 50) {
			printf("Case #%d: white\n", c);
		} else {
			double angle = atan2(X - 50, Y - 50);
			if (angle < 0) {
				angle += 2 * M_PI;
			}
			printf("Case #%d: %s\n", c, angle <= 2 * M_PI * P / 100 ? "black" : "white");
		}
	}
}
