#include <bits/stdc++.h>
using namespace std;

int p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}, divs = 0;
string f;

int main()
{
	for (int i = 0; i < 15 && divs <= 1; i++)
	{
		cout << p[i] << endl;
		fflush(stdout);
		cin >> f;
		if (f == "yes")
		{
			divs++;

			if (p[i] * p[i] < 100)
			{
				cout << p[i] * p[i] << endl;
				fflush(stdout);
				cin >> f;
				if (f == "yes")
					divs++;
			}
		}
	}

	cout << (divs >= 2 ? "composite" : "prime") << endl;
	fflush(stdout);
	return 0;
}