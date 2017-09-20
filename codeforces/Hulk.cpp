#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++)
		if (i % 2)
			printf("I hate that ");
		else
			printf("I love that ");
	if (n % 2)
		printf("I hate it");
	else
		printf("I love it");
}
