#include <bits/stdc++.h>
using namespace std;

int n, a[100];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	while (true)
	{
		bool done = true;

		for (int i = 0; i < n - 1; i++)
			if (a[i] > a[i + 1])
			{
				cout << i + 1 << " " << i + 2 << endl;
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				done = false;
			}
	
		if (done)
			break;
	}

	return 0;
}