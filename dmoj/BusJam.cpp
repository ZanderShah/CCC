#include <bits/stdc++.h>
using namespace std;

int N, M, H, t[1000];

int main()
{
	scanf("%d %d %d", &N, &M, &H);
	int b = 0;
	for (int i = 0; i < N; i++)
		scanf("%d", &t[i]);
	for (int i = N - 1; i >= 1; i--)
		while (abs(t[i] - t[i - 1]) > H)
		{
			t[i - 1] += M;
			b++;
		}

	printf("%d", b);
}
