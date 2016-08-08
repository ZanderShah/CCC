#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int N, a, b;

int main()
{
	scanf("%d", &N);
	for (int i = 0, x, y; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		if (x > y)
			a++;
		else if (y > x)
			b++;
	}

	if (a > b)
		printf("Mishka");
	else if (b > a)
		printf("Chris");
	else
		printf("Friendship is magic!^^");
}
