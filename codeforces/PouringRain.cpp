#include <bits/stdc++.h>
# define PI 3.14159265358979323846

using namespace std;

double d, h, v, e, r;

int main()
{
	cin >> d >> h >> v >> e;
	r = d / 2;
	e *= r * r * PI;

	if (e >= v)
		cout << "NO";
	else
		cout << "YES" << endl << PI * r * r * h / (v - e);

	return 0;
}