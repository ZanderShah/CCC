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

int n, c, last, run;

int main() {
	scanf("%d %d", &n, &c);
	last = run = 0;
	for (int i = 0, x; i < n; i++) {
		scanf("%d", &x);
		if (x - last <= c)
			run++;
		else
			run = 1;
		last = x;
	}
	printf("%d", run);
}
