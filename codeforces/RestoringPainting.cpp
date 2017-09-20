#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d;

int main()
{
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	long long ans = 0;

	for (int i = 1; i <= n; i++)
	{
		int x = a + b + i;
		if (x - a - c >= 1 && x - a - c <= n && x - b - d >= 1 
			&& x - b - d <= n && x - c - d >= 1 && x - c - d <= n)
			ans++;
	}

	cout << n * ans;
	return 0;
}