#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

int n, q, a, b, c;
char t;
map<int, map<int, int> > m;
map<int, int> x, y;

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		m[a][b]++;
		x[a]++;
		y[b]++;
	}
	for (int i = 0; i < q; i++) {
		scanf("%d", &c);
		if (c == 1) {
			scanf("%d %d", &a, &b);
			if (m.find(a) != m.end() && m[a].find(b) != m[a].end())
				printf("salty\n");
			else
				printf("bland\n");
		} else {
			scanf(" %c %d", &t, &a);

			if (t == 'X')
				printf("%d\n", x[a]);
			else
				printf("%d\n", y[a]);
		}
	}
}
