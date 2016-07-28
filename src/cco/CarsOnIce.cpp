#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int N, M;
char s[2000], g[2000][2000];

void dfs(int i, int j)
{
	if (g[i][j] == 'N')
	{
		for (int a = i - 1; a >= 0; a--)
			if (g[a][j] != '.')
				dfs(a, j);
	}
	else if (g[i][j] == 'S')
	{
		for (int a = i + 1; a < N; a++)
			if (g[a][j] != '.')
				dfs(a, j);

	}
	else if (g[i][j] == 'W')
	{
		for (int a = j - 1; a >= 0; a--)
			if (g[i][a] != '.')
				dfs(i, a);
	}
	else
	{
		for (int a = j + 1; a < M; a++)
			if (g[i][a] != '.')
				dfs(i, a);
	}

	g[i][j] = '.';
	printf("(%d,%d)\n", i, j);
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%s", &g[i]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (g[i][j] != '.')
				dfs(i, j);
}