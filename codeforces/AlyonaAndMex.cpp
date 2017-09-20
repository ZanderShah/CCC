#include <bits/stdc++.h>
using namespace std;
int n, a[1000000], minv;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	minv = 1;
	for (int i = 0; i < n; i++)
		if (a[i] >= minv)
			minv++;
	printf("%d", minv);
	return 0;
}