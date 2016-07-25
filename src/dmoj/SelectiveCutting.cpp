#include <bits/stdc++.h>
using namespace std;

int N, Q, bit[100001], ans[100000];

struct query
{
	int i, l, r, m;

	bool operator<(const query& q) const 
	{
    	return m > q.m;
  	}
} q[100000];

struct tree
{
	int i, m;

	bool operator<(const tree& t) const
	{
		return m > t.m;
	}
} t[100000];

void update(int i, int x)
{
	for (; i <= 100000; i += i & (-i))
		bit[i] += x;
}

int sum(int i)
{
	int ret = 0;
	for (; i > 0; i -= i & (-i))
		ret += bit[i];
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0, m; i < N; i++)
	{
		scanf("%d", &m);
		t[i] = { i + 1, m };
	}
	sort(t, t + N);

	scanf("%d", &Q);
	for (int i = 0, l, r, m; i < Q; i++)
	{
		scanf("%d %d %d", &l, &r, &m);
		q[i] = { i, l, r, m };
	}
	sort(q, q + Q);

	for (int i = 0, j = 0; i < Q; i++)
	{
		while (j < N && q[i].m <= t[j].m)
		{
			update(t[j].i, t[j].m);
			j++;
		}

		ans[q[i].i] = sum(q[i].r + 1) - sum(q[i].l);
	}

	for (int i = 0; i < Q; i++)
		printf("%d\n", ans[i]);
}