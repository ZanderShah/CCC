#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

int n, l, v1, v2, k;
double low, high, best;

bool bus(double t)
{
	int p = n;
	double pos = 0, times = 0;

	while (p > k)
	{
		double dest = (t * v1 * v2 - times * v1 * v2 + pos * v1 - 1.0 * v2 * l) / (v1 - v2);

		double curTimes = (dest - pos) / v2;

		pos += curTimes * v1;

		dest = (v1 * dest + v2 * pos) / (v1 + v2);

		times += curTimes + (dest - pos) / v1;
		pos = dest;
		p -= k;
	}

	return (l - pos) / v2 <= (t - times);
}

int main()
{
	cin >> n >> l >> v1 >> v2 >> k;
	best = l * 1.0 / v1;

	low = 0, high = (ceil) (n * 1.0 / k) * l * 2 / v2;

	while (high - low >= EPS * high)
	{
		if (bus((low + high) / 2))
			high = (low + high) / 2 - EPS;
		else
			low = (low + high) / 2 + EPS;
	}

	cout << setprecision(9) << high;
}