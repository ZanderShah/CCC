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
#include <bitset>

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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;

int x, y, dx = 1, dy = 1, T, dp[2505][2505], t[2505][2505], r[2505][2505];

int walk(int x, int y) {
	if (x == 0 && y == 0)
		return 0;
	if (dp[y][x] != -1)
		return dp[y][x];
	int ret = 2005;
	if (x - 1 >= 0)
		ret = min(ret, walk(x - 1, y) + r[y][x - 1]);
	if (y - 1 >= 0)
		ret = min(ret, walk(x, y - 1) + t[y - 1][x]);
	return dp[y][x] = ret;
}

int main() {
	scanf("%d %d", &x, &y);
	if (x < 0) {
		x = -x;
		dx = -dx;
	}
	if (y < 0) {
		y = -y;
		dy = -dy;
	}

	scanf("%d", &T);
	for (int i = 0, xx, yy, l; i < T; i++) {
		scanf("%d %d %d", &xx, &yy, &l);
		xx *= dx;
		yy *= dy;

		if (yy + l >= 0 && yy + l <= y)
			for (int j = max(xx - l, 0); j <= min(xx + l, x); j++)
				t[yy + l][j]++;
		if (xx + l >= 0 && xx + l <= x)
			for (int j = max(yy - l, 0); j <= min(yy + l, y); j++)
				r[j][xx + l]++;
	}

	for (int i = 0; i <= y; i++)
		for (int j = 0; j <= x; j++)
			dp[i][j] = -1;

	printf("%d\n", walk(x, y));
}
