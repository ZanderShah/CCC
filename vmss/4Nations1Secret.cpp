#include <bits/stdc++.h>
using namespace std;

int N, best = 1, start = 0;
char c[25000];

int main()
{
	scanf("%d", &N);
	scanf("%s", c);

	for (int i = 0; i < N; i++)
		for (int j = N - 1; j > i && j - i + 1 > best; j--)
		{
			int a = i, b = j;
			while (a < b)
				if (c[a] == c[b])
				{
					a++;
					b--;
				}
				else
				{
					break;
				}

			if (a >= b)
			{
				best = j - i + 1;
				start = i;
			}
		}

	for (int i = start; i < start + best; i++)
		printf("%c", c[i]);
	printf("\n%d", best);
}
