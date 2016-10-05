#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>

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

int c, a[2], p;
char b[5];

int main() {
	scanf("%d", &c);
	for (int i = 0, x; i < c; i++) {
		scanf("%d", &x);
		if (x != 4) {
			scanf(" %s", b);
			p = b[0] == 't';
		}
		if (x == 1) {
			printf("%s\n", a[p] ? "false" : "true");
			a[p] = 1;
		} else if (x == 2) {
			printf("%s\n", a[p] ? "true" : "false");
			a[p] = 0;
		} else if (x == 3) {
			if (a[p])
				printf("%d\n", a[0] && p ? 1 : 0);
			else
				printf("-1\n");
		} else if (x == 4) {
			if (a[0] && a[1])
				printf("false true\n");
			else if (a[0])
				printf("false\n");
			else if (a[1])
				printf("true\n");
		}
	}
}
