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

int n;
pii line[100005];
unordered_map<int, unordered_map<int, int> > m;
long long ans = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &line[i].x, &line[i].y);

		m[line[i].x][line[i].y]++;

		if (m[line[i].x][line[i].y] > 1) {
			printf("Infinity");
			return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		ans += n - m[line[i].x].size();
	}

	printf("%lld", ans / 2);
}