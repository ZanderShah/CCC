#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

int main()
{
	cin >> a >> b >> c;
	if (!c)
		cout << (a == b ? "YES" : "NO");
	else if ((b - a) * c < 0)
		cout << "NO";
	else if (b - a < 0)
		cout << (!((a - b) % -c) ? "YES" : "NO");
	else
		cout << (!((b - a) % c) ? "YES" : "NO");
}