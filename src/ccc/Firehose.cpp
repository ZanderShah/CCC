#include <bits/stdc++.h>
using namespace std;

int H, houses[2000], K;

bool valid(int l)
{
	int cur = 0, hydrants = 1;
	// Go through every house
	for (int i = 0; i < H; i++)
		if (houses[i] - houses[cur] > 2 * l)
		{
			cur = i;
			hydrants++;
		}

	return hydrants <= K;
}

int main()
{
	scanf("%d", &H);
	for (int i = 0; i < H; i++)
		scanf("%d", &houses[i]);;
	sort(houses, houses + H);
	for (int i = 0; i < H; i++)
		houses[i + H] = houses[i] + 1000000;
	scanf("%d", &K);

	int low = 0, up = 1000000;
	while (low < up)
	{
		if (valid((low + up) / 2))
			up = (low + up) / 2;
		else
			low = (low + up) / 2 + 1;
	}

	printf("%d", low);
}
