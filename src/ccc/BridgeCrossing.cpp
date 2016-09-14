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

int M, Q, t[101], dp[101];
char n[101][101];
stack<int> store;

int speed(int l, int r) {
	int ret = t[l];
	for (int i = l + 1; i <= r; i++)
		ret = max(ret, t[i]);
	return ret;
}

int main() {
	scanf("%d %d", &M, &Q);
	for (int i = 1; i <= Q; i++)
		scanf(" %s %d", n[i], &t[i]);

	for (int i = 1; i <= Q; i++)
		for (int j = 1; j <= min(i, M); j++)
			if (dp[i])
				dp[i] = min(dp[i], dp[i - j] + speed(i - j + 1, i));
			else
				dp[i] = dp[i - j] + speed(i - j + 1, i);

	for (int i = Q; dp[i];)
		for (int j = 1; j <= min(i, M); j++)
			if (dp[i - j] + speed(i - j + 1, i) == dp[i]) {
				i -= j;
				store.push(j);
			}

	printf("Total Time: %d\n", dp[Q]);
	for (int i = 1, p; !store.empty(); i += p) {
		p = store.top();
		store.pop();
		for (int j = 0; j < p; j++)
			printf("%s ", n[i + j]);
		printf("\n");
	}
}
