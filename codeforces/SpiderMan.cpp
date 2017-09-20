#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int n, turn = 1;

int main()
{
	scanf("%d", &n);
	for (int i = 0, x; i < n; i++)
	{
		scanf("%d", &x);
		if (i == 0 && x == 1)
			printf("2\n");
		else
		{
			if (x % 2 == 0)
				turn ^= 3;
			printf("%d\n", turn ^ 3);
		}
	}
}
