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

int n, l1, a1, l2, a2, l, a;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d %d %d", &l1, &a1, &l2, &a2, &l, &a);
		int m = 0;
		pii g = mp(0, 0);
		for (int j = 1; l1 * j < l && a1 * j < a; j++) {
			if ((l - l1 * j) % l2 == 0 && (a - a1 * j) % a2 == 0
					&& (l - l1 * j) / l2 == (a - a1 * j) / a2) {
				g = mp(j, (l - l1 * j) / l2);
				m++;
			}
		}
		if (m != 1)
			printf("?\n");
		else
			printf("%d %d\n", g.x, g.y);
	}
}
