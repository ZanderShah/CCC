#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 1e6;
int n, b, d, t, e;

int main() {
	scanf("%d %d %d", &n, &b, &d);
	for (int i = 0, x; i < n; i++) {
		scanf("%d", &x);
		if (x <= b)
			t += x;
		if (t > d) {
			t = 0;
			e++;
		}
	}
	printf("%d", e);
}
