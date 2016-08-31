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

const int MAXN = 1e5 + 1;

int N, K, row[MAXN], col[MAXN], d1[3 * MAXN], d2[3 * MAXN];

int main() {
	scan(N);
	scan(K);
	for (int i = 1, x, y; i <= N; i++) {
		scan(x);
		scan(y);
		row[x]++;
		col[y]++;
		d1[y - x + MAXN]++;
		d2[x + y]++;

		if (row[x] == K || col[y] == K || d1[y - x + MAXN] == K
				|| d2[x + y] == K) {
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
}
