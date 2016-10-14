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

int c, n, bit[1025][1025], X, Y, A, L, B, R, T;

void update(int x, int y, int v) {
	for (; x <= n; x += x & -x)
		for (int yo = y; yo <= n; yo += yo & -yo)
			bit[x][yo] += v;
}

int query(int x, int y) {
	int ret = 0;
	for (; x; x -= x & -x)
		for (int yo = y; yo; yo -= yo & -yo)
			ret += bit[x][yo];
	return ret;
}

int main() {
	scanf("%d %d", &c, &n);
	while (c != 3) {
		scanf("%d", &c);
		if (c == 1) {
			scanf("%d %d %d", &X, &Y, &A);
			update(X + 1, Y + 1, A);
		} else if (c == 2) {
			scanf("%d %d %d %d", &L, &B, &R, &T);
			printf("%d\n",
					query(R + 1, T + 1) - query(R + 1, B) - query(L, T + 1)
							+ query(L, B));
		}
	}
}
