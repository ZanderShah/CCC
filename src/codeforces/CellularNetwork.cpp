#include <bits/stdc++.h>
using namespace std;

int N, M, a[100001], b[100001];

bool valid(long long r)
{
	for (int i = 0, j = 0; i < N; i++)
	{
		while (j < M && abs(a[i] - b[j]) > r)
			j++;
		if (j == M)
			return false;
	}
	return true;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	sort(a, a + N);
	for (int i = 0; i < M; i++)
		scanf("%d", &b[i]);
	sort(b, b + M);

	long long low = 0, up = 1ll << 31;
	while (low <= up)
	{
		if (valid((low + up) / 2))
			up = (low + up) / 2 - 1;
		else
			low = (low + up) / 2 + 1;
	}
	printf("%I64d", low);
}
