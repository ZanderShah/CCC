#include <bits/stdc++.h>
using namespace std;

int n, m, p[1000001];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 0, a, b; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		int t = p[a];
		p[a] = p[b];
		p[b] = t;

		for (int i = 1; i <= n; i++)
			cout << p[i] << " ";
		cout << endl;
	}
}