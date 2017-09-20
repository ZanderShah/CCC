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

const int MAXN = 3e6 + 1;

int N, K, a[MAXN], c[MAXN];
priority_queue<int> minv, maxv;

int main() {
	scan(N); scan(K);
	for (int i = 0; i < N; i++)
		scan(a[i]);

	ll ans = 0;

	for (int i = 0, j = 0; i < N; i++) {
		while (!minv.empty() && !c[-minv.top()])
			minv.pop();
		while (!maxv.empty() && !c[maxv.top()])
			maxv.pop();

		if (i == j) {
			c[a[i]]++;
			minv.push(-a[i]);
			maxv.push(a[i]);
			j++;
		}

		while (j < N && max(maxv.top(), a[j]) + max(minv.top(), -a[j]) <= K) {
			c[a[j]]++;
			minv.push(-a[j]);
			maxv.push(a[j]);
			j++;
		}

		c[a[i]]--;
		ans += j - i;
	}

	printf("%lld", ans);
}
