#include <bits/stdc++.h>
using namespace std;

int N, R, E, CA, CB, CM, VA, VB, VM;
long long C, V, dp[2001], x, zero = 0;
priority_queue<long long> q[2001];

int main()
{
	scanf("%d %d", &N, &R);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d %d %d %d %d %d", &E, &C, &V, &CA, &CB, &CM, &VA, &VB, &VM);
		C %= CM;
		CA %= CM;
		CB %= CM;
		V %= VM;
		VA %= VM;
		VB %= VM;
		for (int j = 0; j < E; j++)
		{
			if (C <= R)
			{
				if (C == 0)
					zero += V;
				else if (q[C].size() == 0 || q[C].size() <= R / C)
					q[C].push(-V);
				else if (q[C].size() > R / C && q[C].top() > -V)
				{
					q[C].pop();
					q[C].push(-V);
				}
			}

			C = (C * CA % CM + CB) % CM;
			V = (V * VA % VM + VB) % VM;
		}
	}

	for (int i = 0; i <= R; i++)
		while (!q[i].empty())
		{
			// Nvm
			x = q[i].top();
			q[i].pop();

			for (int j = R; j >= i; j--)
				dp[j] = max(dp[j], dp[j - i] - x);
		}
	
	printf("%lld", dp[R] + zero);
}