#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int n, k, c[100000];
bool v[100000];
long long t, xxx;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
		t += c[i];

		if (i)
			xxx += c[i] * c[i - 1];
	}
	xxx += c[n - 1] * c[0];
	for (int i = 0, x; i < k; i++)
	{
		scanf("%d", &x);
		xxx += (t - c[x - 1] - (!v[(x - 2 + n) % n] ? c[(x - 2 + n) % n] : 0)
				- (!v[x % n] ? c[x % n] : 0)) * c[x - 1];
		v[x - 1] = true;
		t -= c[x - 1];
	}
	printf("%I64d", xxx);
}
