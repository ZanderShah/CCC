#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int K, m[500], t;
long long f[500000];

long long p(long long x, long long e)
{
	long long ret = 1;
	for (int i = 0; i <= 30; i++, x = x * x % MOD)
		if (e & (1ll << i))
			ret = ret * x % MOD;
	return ret;
}

long long nCr(int n, int r)
{
	return max(f[n] * p(f[r], MOD - 2) % MOD * p(f[n - r], MOD - 2) % MOD, 1ll);
}

int main()
{
	f[1] = 1;
	for (int i = 2; i <= 500; i++)
		f[i] = f[i - 1] * i % MOD;

	scanf("%d", &K);
	t = -1;
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &m[i]);
		t += m[i];
	}

	long long ans = 1;
	for (int i = K - 1; i >= 1; i--)
	{
		ans = ans * nCr(t, m[i] - 1) % MOD;
		t -= m[i];
	}
	printf("%lld", ans);
}
