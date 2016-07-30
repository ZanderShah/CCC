#include <bits/stdc++.h>
using namespace std;

int N;
unordered_map<long long, int> m;

int main()
{
	scanf("%d", &N);
	long long ans = 0;
	for (int i = 0, x; i < N; i++)
	{
		scanf("%d", &x);
		for (int i = 0; i < 32; i++)
			if ((1ll << i) >= x)
				ans += m[(1ll << i) - x];
		m[x]++;
	}
	printf("%I64d", ans);
}
