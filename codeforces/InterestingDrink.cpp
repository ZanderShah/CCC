#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int n, c[100000], q;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	sort(c, c + n);
	scanf("%d", &q);
	for (int i = 0, x, l, r; i < q; i++)
	{
		scanf("%d", &x);
		printf("%d\n", upper_bound(c, c + n, x) - c);
	}
}
