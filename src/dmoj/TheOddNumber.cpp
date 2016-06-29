#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
unordered_set<int> s;

int main()
{
	scanf("%d", &n);
	for (int i = 0, x; i < n; i++)
	{
		scanf("%d", &x);
		ans ^= x;
	}

	printf("%d", ans);
	return 0;
}