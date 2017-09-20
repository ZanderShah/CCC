#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, d, ans = 0;
int dp[1 << 20];

void go(int v, int k) {
	if (dp[v] == 101)
		ans++;

	dp[v] = k;

	if (k + a <= m)
		for (int i = 0, x = 1 << (n - 1); i < n; i++, x /= 2)
			if ((v & x) != 0 && dp[v - x] > k + a)
				go(v - x, k + a);
			else if ((v & x) == 0 && dp[v + x] > k + a)
				go(v + x, k + a);

	if (k + b <= m) {
		if ((v & (1 << (n - 1))) != 0
				&& dp[((v - (1 << (n - 1))) << 1) + 1] > k + b)
			go(((v - (1 << (n - 1))) << 1) + 1, k + b);
		else if ((v & (1 << (n - 1))) == 0 && dp[v << 1] > k + b)
			go(v << 1, k + b);
	}

	if (k + c <= m) {
		if ((v & 1) != 0 && dp[(v >> 1) + (1 << (n - 1))] > k + c)
			go((v >> 1) + (1 << (n - 1)), k + c);
		else if ((v & 1) == 0 && dp[v >> 1] > k + c)
			go(v >> 1, k + c);
	}

	if (k + d <= m) {
		int o = v;
		for (int i = 0, x = 1 << (n - 1); i < n; i++, x /= 2)
			if ((v & x) != 0)
				o -= x;
			else
				o += x;

		if (dp[o] > k + d)
			go(o, k + d);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d %d", &a, &b, &c, &d);
	char s[n];
	scanf("%s", s);

	int v = 0;
	for (int i = 0, x = 1 << (n - 1); i < n; i++, x /= 2)
		if (s[i] == 'B')
			v += x;

	for (int i = 0; i < (1 << n); i++)
		dp[i] = 101;

	go(v, 0);
	printf("%d", ans);

	return 0;
}
