#include <cstdio>
#include <iostream>
#include <type_traits>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 500, DIR[4][2] = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };

int l, t, d;
int g[MAXN][MAXN];
char c;

void update(int i, int j, int a, int b) {
	if (i > a)
		swap(i, a);
	if (j > b)
		swap(j, b);
	for (int x = i; x <= a; x++)
		for (int y = j; y <= b; y++)
			g[x + MAXN / 2][y + MAXN / 2] = 1;
}

int main() {
	update(-1, 0, -3, 0);
	update(-3, 0, -3, 3);
	update(-3, 3, -5, 3);
	update(-5, 3, -5, 5);
	update(-5, 5, -3, 5);
	update(-3, 5, -3, 7);
	update(-3, 7, -7, 7);
	update(-7, 7, -7, -1);
	update(-7, -1, -5, -1);

	int x = -5, y = -1;
	while (true) {
		scanf(" %c %d", &c, &l);

		if (c == 'q')
			break;

		if (c == 'l')
			d = 0;
		else if (c == 'r')
			d = 1;
		else if (c == 'u')
			d = 2;
		else
			d = 3;

		for (int i = 1; i <= l; i++) {
			if (g[x + DIR[d][0] * i + MAXN / 2][y + DIR[d][1] * i + MAXN / 2]) {
				printf("%d %d DANGER", y + DIR[d][1] * l, x + DIR[d][0] * l);
				return 0;
			}
			g[x + DIR[d][0] * i + MAXN / 2][y + DIR[d][1] * i + MAXN / 2] = 1;
		}
		x += DIR[d][0] * l;
		y += DIR[d][1] * l;
		printf("%d %d safe\n", y, x);
	}
}
