#include <cstdio>
#include <iostream>
#include <vector>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 1010;

int R, C, W, L, N;
bool g[MAXN][MAXN];

bool checkLocation(int x, int y) {
	for (int i = max(x - W, 0); i < x + W; i++)
		for (int j = max(y - L, 0); j < y + L; j++) {
			int s = 0;
			for (int a = 0; a < W; a++)
				for (int b = 0; b < L; b++)
					s += g[i + a][j + b];
			if (s == W * L)
				return 1;
		}
	return 0;
}

int main() {
	scanf("%d %d %d %d %d", &R, &C, &W, &L, &N);
	for (int i = 1, x, y; i <= N; i++) {
		scanf("%d %d", &x, &y);
		g[x][y] = 1;
		if (checkLocation(x, y)) {
			printf("Special store was found on: %d", i);
			return 0;
		}
	}
	printf("Special store was not located");
}
