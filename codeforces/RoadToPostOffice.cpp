#include <bits/stdc++.h>
using namespace std;

unsigned long long d, best, k, a, b, t;

int main()
{
	cin >> d >> k >> a >> b >> t;
	// Case 1: No repair
	// Case 2: Break car
	// Case 3: Ride car close
	if (k >= d)
		best = d * a;
	else if (t + k * a > k * b)
		best = k * a + (d - k) * b;
	else if (d % k)
		best = (d / k - 1) * t + d / k * k * a + min(d % k * a + t, d % k * b);
	else
		best = (d / k - 1) * t + d * a;
	printf("%I64d", best);
}
