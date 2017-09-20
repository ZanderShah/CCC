#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <queue>
#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 505;

int n, x, y, g[MAXN][MAXN];
ll r[MAXN], c[MAXN], d1, d2, diff;
bool valid;

int update(int i, int j, ll v) {
	r[i] += v;
	c[j] += v;
	if (i == j)
		d1 += v;
	if (i == n - j - 1)
		d2 += v;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &g[i][j]);
			if (!g[i][j]) {
				x = i;
				y = j;
			}
			update(i, j, g[i][j]);
		}

	diff = max(r[(x + 1) % n] - r[x], 1ll);
	update(x, y, diff);
	valid = true;

	for (int i = 0; i < n; i++)
		if (r[i] != c[i] || r[i] != r[0])
			valid = false;

	if (!valid || d1 != d2 || d1 != c[0])
		diff = -1;
	printf("%I64d", diff);
}
