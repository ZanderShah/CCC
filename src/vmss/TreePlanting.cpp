#include <bits/stdc++.h>
using namespace std;

// Strange bit
int N, bit[5000][5000];

int update(int r, int c, int v)
{
	int x = c + r + 1;
	for (; r <= 5000; r += r & (-r))
		bit[x] += v;
}	

int query(int x, int r)
{
	int ret = 0;
	for (; r; r -= r & (-r))
		ret += bit[x][r];
	return ret;
}

int query(int r, int c, int v)
{
	int x = c + r + 1;
	return query(x, r) - query(x, c - v - 1);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0, t, r, c, x; i < N; i++)
	{
		scanf("%d %d %d %d", &t, &r, &c, &x);
		if (t == 1)
			update(r, c, x);
		else
			printf("%d\n", query(r, c, x));
	}
}