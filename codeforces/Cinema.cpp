#include <bits/stdc++.h>
using namespace std;

int n, b[200001], c[200001], movie = 0;
map<int, int> u;

int main()
{
	scanf("%d", &n);

	for (int i = 0, x; i < n; i++)
	{
		scanf("%d", &x);
		u[x]++;
	}

	scanf("%d", &n);
	for (int i = 0, x; i < n; i++)
	{
		scanf("%d", &x);
		b[i] = u[x];
	}
	for (int i = 0, x; i < n; i++)
	{
		scanf("%d", &x);
		c[i] = u[x];
	}

	for (int i = 0; i < n; i++)
		if (b[movie] < b[i] || (b[movie] == b[i] && c[movie] < c[i]))
			movie = i;

	printf("%d", movie + 1);

	return 0;
}