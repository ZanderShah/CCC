#include <bits/stdc++.h>
using namespace std;

int N, Q, b, c;

int main()
{
	scanf("%d", &N);
	for (int i = 0, x; i < N; i++)
	{
		scanf("%d", &x);
		if (x > b)
		{
			b = x;
			c = 1;
		}
		else if (x == b)
		{
			c++;
		}
	}

	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
		printf("%d %d\n", b, c);
}