#include <bits/stdc++.h>
using namespace std;

int n;
long long big = -1, sum = 0, x;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		big = max(big, x);
		sum += x;
	}
	sum -= big;

	cout << max(sum - big, big - sum) + 1;
}