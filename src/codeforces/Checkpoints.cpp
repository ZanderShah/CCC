#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 1e5;
int n, a, x[MAXN + 1];

int main() {
	scanf("%d %d", &n, &a);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);

	if (n == 1) {
		printf("0");
		return 0;
	} else if (n == 2) {
		printf("%d", min(abs(x[1] - a), abs(x[0] - a)));
		return 0;
	}

	x[n] = a;
	sort(x, x + n + 1);

	int start = lower_bound(x, x + n, a) - x;

	if (start == 0) {
		printf("%d", x[n - 1] - x[0]);
	} else if (start == n) {
		printf("%d", x[n] - x[1]);
	} else {
		printf("%d",
				min(x[n - 1] - x[0] + min(x[n - 1] - x[start], x[start] - x[0]),
						x[n] - x[1] + min(x[n] - x[start], x[start] - x[1])));
	}
}
