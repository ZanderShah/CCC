#include <bits/stdc++.h>
using namespace std;

int n, k;
long long a[100000], b[100000];

bool valid (long long x)
{
	long long left = k;
	for (int i = 0; i < n; i++)
	{
		if (b[i] < a[i] * x)
			left -= a[i] * x - b[i];
		if (left < 0)
			return false;
	}

	return true;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &b[i]);

	long long low = 0, high = 2e9;

	while (low <= high)
	{
		if (valid((low + high) / 2))
			low = (low + high) / 2 + 1;
		else
			high = (low + high) / 2 - 1;
	}

	printf("%I64d", high);

	return 0;
}