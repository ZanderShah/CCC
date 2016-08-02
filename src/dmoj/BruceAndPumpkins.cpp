#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<int> a, b;

int main()
{
	scanf("%d", &N);
	scanf("%d", &T);

	a.push_back(0);
	b.push_back(0);
	for (int i = 1, x; i <= N; i++)
	{
		scanf("%d", &x);
		if (x < 0)
			a.push_back(-x);
		else
			b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int best = 4000;
	for (int i = 0; i <= T; i++)
		if (a.size() > i && b.size() > T - i)
			best = min(best, 2 * min(a[i], b[T - i]) + max(a[i], b[T - i]));
	printf("%d", best);
}
