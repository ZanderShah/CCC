#include <bits/stdc++.h>
using namespace std;

int N, M, f[50];
bitset<50> dp[1 << 20];
char s[50];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0, AC = M; i < N; i++, AC = M)
	{
		scanf("%s", &s);

		for (int j = 0; j < M; j++)
			if (s[j] == 'X')
			{
				f[j] |= 1 << i;
				AC--;
			}

		if (AC == M)
			for (int j = 0; j < M; j++)
				f[j] |= 1 << i;
	}	

	for (int i = 0; i < 1 << N; i++)
		for (int j = 0; j < M; j++)
			if (f[j] && (dp[i].count() || i == 0))
			{
				if (dp[i | f[j]].count() > dp[i].count() + 1 || dp[i | f[j]].count() == 0)
				{	
					dp[i | f[j]] = dp[i];
					dp[i | f[j]][j] = 1;
				}
			}

	printf("%d\n", dp[(1 << N) - 1].count());
	for (int i = 0; i < M; i++)
	 	if (dp[(1 << N) - 1][i])
	 		printf("%d ", i + 1);
}