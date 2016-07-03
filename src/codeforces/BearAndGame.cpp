#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	cin >> n;
	int t = 0;

	for (int i = 0, x; i < n; i++)
	{
		cin >> x;
		if (x - t > 15)
		{
			cout << t + 15;
			return 0;
		}
		else
			t = x;
	}

	cout << max(t, min(t + 15, 90));

	return 0;
}