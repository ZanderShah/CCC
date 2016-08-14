#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int n, a[101][101];

int main()
{
	scanf("%d", &n);
	while (n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);

		bool group = true;
		int identity = -1;

		// Associativity
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					if (a[i][a[j][k]] != a[a[i][j]][k])
						group = false;
		// Identity
		for (int i = 1; i <= n; i++)
		{
			bool isIdentity = true;
			for (int j = 1; j <= n; j++)
				if (a[i][j] != j || a[j][i] != j)
					isIdentity = false;
			if (isIdentity)
				identity = i;
		}
		// Inverse
		for (int i = 1; i <= n; i++)
		{
			bool inverse = false;
			for (int j = 1; j <= n; j++)
				if (a[i][j] == identity && a[j][i] == identity)
					inverse = true;
			if (!inverse)
				group = false;
		}

		printf("%s\n", group ? "yes" : "no");
		scanf("%d", &n);
	}
}
