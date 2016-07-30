#include <bits/stdc++.h>
using namespace std;

int N;
long long t = 0, m = 0; 

int main()
{
	scanf("%d", &N);
	for (int i = 0, x; i < N; i++)
	{
		scanf("%d", &x);
		t += x;
		m = max(m, x);
	}
	printf("%lld", max(2 * m, t));
}