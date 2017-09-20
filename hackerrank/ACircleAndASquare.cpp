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

const double EPS = 1e-6;

int w, h, r, g[105][105];
double a;
pdd p1, p3, c, m, d, p2, p4, p;

double area(pdd a, pdd b, pdd c) {
	return abs(a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - c.x * b.y - b.x * a.y) / 2;
}

int main () {
	scanf("%d %d", &w, &h);
	scanf("%lf %lf %d", &c.x, &c.y, &r);
	scanf("%lf %lf %lf %lf", &p1.x, &p1.y, &p3.x, &p3.y);

	m = mp((p1.x + p3.x) / 2, (p1.y + p3.y) / 2);
	d = mp((p1.x - p3.x) / 2, (p1.y - p3.y) / 2);
	p2 = mp(m.x - d.y, m.y + d.x);
	p4 = mp(m.x + d.y, m.y - d.x);
	a = area(p1, p2, p3) * 2;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if ((j - c.x) * (j - c.x) + (i - c.y) * (i - c.y) <= r * r) {
				g[i][j] = 1;
			}
			p = mp(j, i);

			if (abs(a - (area(p, p1, p2) + area(p, p2, p3) + area(p, p3, p4) + area(p, p4, p1))) <= EPS) {
				g[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%c", g[i][j] ? '#' : '.');
		}
		printf("\n");
	}
}
