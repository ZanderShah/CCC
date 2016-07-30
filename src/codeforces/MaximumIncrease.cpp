#include <bits/stdc++.h>
using namespace std;

int N, a[100001];

int main()
{
	scanf("%d", &N);
	int cur = 0, best = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > a[i - 1])
		{
			cur++;
			best = max(best, cur);
		}
		else
		{
			cur = 1;
		}
	}
	printf("%d", best);
	return 0;
}
