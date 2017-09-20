#include <bits/stdc++.h>
using namespace std;

long long n, m, r = 0, c = 0, t;
bool row[100001], col[100001];

int main()
{
	scanf("%I64d %I64d", &n, &m);
	
	for (int i = 0, a, b; i < m; i++)
	{
		scanf("%d %d", &a, &b);

		if (!row[a])
		{		
			row[a] = true;
			r++;
		}

		if (!col[b])
		{
			col[b] = true;
			c++;
		}

		t = n;
		t *= n;
		t -= n * r;
		t -= (n - r) * c;

		printf("%I64d ", t);
	}
}