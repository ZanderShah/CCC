#include <bits/stdc++.h>
using namespace std;

// One misplaced negative sign can ruin your whole day

int M, N, Q, a[200001], b[200001];

void update(int* bit, int i, int x)
{
	for (; i <= 200000; i += i & (-i))
		bit[i] = (bit[i] + x) % M;
}

void update(int l, int r, int x)
{
	update(a, l, x);
	update(a, r + 1, -x + M);
	update(b, l, (l - 1) % M * x);
	update(b, r + 1, r % M * (-x + M));
}

int query(int* bit, int i)
{
	int ret = 0;
	for (; i > 0; i -= i & (-i))
		ret = (ret + bit[i]) % M;
	return ret;
}

int query(int i)
{
	return (query(a, i) * i - query(b, i) + M) % M;
}

int query(int l, int r)
{
	return (query(r) - query(l - 1) + M) % M;
}

int main()
{
	scanf("%d %d %d", &M, &N, &Q);

	for (int i = 1, x; i <= N; i++)
	{
		scanf("%d", &x);
		update(i, i, x % M);
	}

	for (int i = 0, d, l, r, x; i < Q; i++)
	{
		scanf("%d %d %d", &d, &l, &r);

		if (d == 1)
		{
			scanf("%d", &x);
			update(l, r, x % M);
		}
		else
		{
			printf("%d\n", query(l, r));
		}
	}
}