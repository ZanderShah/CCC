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

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;

int n, m[7];
pff p[7];
float w;

double cross(pff a, pff b) {
	return a.x * b.y - a.y * b.x;
}

double dot(pff a, pff b) {
	return a.x * b.x + a.y * b.y;
}

bool intersect(int i, int j) {
	pff pe = p[m[i]];
	pff r = mp(p[m[(i + 1) % 7]].x - pe.x, p[m[(i + 1) % 7]].y - pe.y);
	pff q = p[m[j]];
	pff s = mp(p[m[(j + 1) % 7]].x - q.x, p[m[(j + 1) % 7]].y - q.y);

	float t = cross(mp(q.x - pe.x, q.y - pe.y), s) / cross(r, s);
	float u = cross(mp(pe.x - q.x, pe.y - q.y), r) / cross(s, r);

	if (cross(r, s) == 0 && cross(mp(q.x - pe.x, q.y - pe.y), r) == 0) {
		float t0 = dot(mp(q.x - pe.x, q.y - pe.y), r) / dot(r, r);
		float t1 = t0 + dot(s, r) / dot(r, r);
		return (max(t0, t1) < 1 && min(t0, t1) > 0);
	} else if (cross(r, s) != 0 && t > 0 && t < 1 && u > 0 && u < 1) {
		pff inter = mp(q.x + u * s.x, q.y + u * s.y);
		if (inter != pe && inter != r && inter != q && inter != s)
			return 1;
	}

	return 0;
}

bool valid() {
	for (int i = 0; i < 7; i++)
		for (int j = i + 1; j < 7; j++)
			if (i != j && intersect(i, j))
				return 0;
	return 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 7; j++) {
			scanf("%f %f", &p[j].x, &p[j].y);
			m[j] = j;
		}
		scanf("%f", &w);

		do {
			double a = 0;
			for (int j = 0; j < 7; j++)
				a += (p[m[j]].x * p[m[(j + 1) % 7]].y
						- p[m[(j + 1) % 7]].x * p[m[j]].y);
			a = 0.5 * abs(a);
			if (abs(a * a * a / 64 - w) <= 1e-5 && valid()) {
				for (int j = 0; j < 7; j++)
					printf("%d ", m[j] + 1);
				printf("\n");
				break;
			}
		} while (next_permutation(m, m + 7));
	}
}
