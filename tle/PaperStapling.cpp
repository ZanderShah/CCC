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
#include <cstdio>
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
typedef unordered_map<int, int> umii;

ll xx1, yy1, xx2, yy2;
double m, b, a;

int main () {
	scanf("%lld %lld %lld %lld", &xx1, &yy1, &xx2, &yy2);
	if (xx2 <= xx1 && yy2 <= yy1) {
		swap(xx1, xx2);
		swap(yy1, yy2);
	}
	if (xx1 <= xx2 && yy1 <= yy2) {
		cout << 2ll * xx2 * yy2;
	} else {
		m = (yy2 - yy1) * 1.0 / (xx2 - xx1);
		b = yy2 - xx2 * m;
		a = -b / m;


		double ans = abs(a * b) / 2;

		double m1 = -1.0 * yy1 / xx1, m2 = -1.0 * yy2 / xx2;
		if (yy2 <= m1 * xx2 + 2 * yy1) {
			ans = min(ans, 2.0 * xx1 * yy1);
		}
		if (yy1 <= m2 * xx1 + 2 * yy2) {
			ans = min(ans, 2.0 * xx2 * yy2);
		}
		printf("%f", ans);
	}
}
