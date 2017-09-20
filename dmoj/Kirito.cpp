#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define mp make_pair
using namespace std;

int N, M, prefix[5000], v, Q;
char g[2000][5000], t;

int rmq(int l, int r)
{
	if (l == r)
		return M;
	int ret = 5000;
	l += N;
	r += N;
	for (; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			ret = min(ret, prefix[l++]);
		if (r & 1)
			ret = min(ret, prefix[--r]);
	}
	return ret;
}

void update(int x)
{
	v = 0;
	while (x < M && g[x - 1][v] == g[x][v])
		v++;
	x += N;
	for (prefix[x] = v; x > 1; x >>= 1)
		prefix[x >> 1] = min(prefix[x], prefix[x ^ 1]);
}

int main()
{
	scan(N);
	scan(M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", g[i]);
		if (i)
		{
			v = 0;
			while (v < M && g[i][v] == g[i - 1][v])
				v++;
			prefix[i + N] = v;
		}
	}
	for (int i = N - 1; i > 0; i--)
		prefix[i] = min(prefix[i << 1], prefix[i << 1 | 1]);

	scan(Q);
	for (int i = 0, l, r; i < Q; i++)
	{
		scan(l);
		scan(r);
		printf("%d\n", rmq(l, r) * (r - l + 1));

		swap(g[l - 1], g[r - 1]);

		if (l > 1)
			update(l - 1);
		update(l);
		if (r > 1)
			update(r - 1);
		update(r);
	}
}
