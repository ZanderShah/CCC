#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
//#define FILE

using namespace std;

int T, M;
long long c[101], d[101];

double root(double x)
{
	double fx = 0, fpx = 0;
	for (int i = 0; i <= M; i++)
	{
		fx += pow(x, M - i) * c[i];
		fpx += pow(x, M - i - 1) * d[i];
	}

	if (fx / fpx <= 1e-10)
		return x - fx / fpx;
	return root(x - fx / fpx);
}

int main()
{
	#ifdef FILE
		freopen("test.in", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif

	scanf("%d", &T);
	for (int r = 1; r <= T; r++)
	{
		scanf("%d", &M);
		for (int i = 0; i <= M; i++)
		{
			scanf("%lld", &c[i]);
			d[i] = c[i] * (M - i);
		}
		c[0] *= -1;
		d[0] *= -1;
		printf("Case #%d: %.10f\n", r, root(2) - 1);
	}
}
