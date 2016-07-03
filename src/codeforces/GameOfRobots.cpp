#include <bits/stdc++.h>
using namespace std;

int n, k;

int main()
{
	scanf("%d %d", &n, &k);

	long long v = 1;
	while (v * (v + 1) / 2 < k)
		v++;
	
	int t = v - v * (v + 1) / 2 + k - 1;

	for (int i = 0, x; i < n; i++)
	{
		scanf("%d", &x);
		if (i == t)
		{
			printf("%d", x);
			return 0;
		}
	}

	return 0;
}