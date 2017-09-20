#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i <= n / 1234567; i++) 
		for (int j = 0; j <= (n - 1234567 * i) / 123456; j++)
			if ((n - 1234567 * i - 123456 * j) % 1234 == 0)
			{
				cout << "YES";
				return 0;
			}
			
	cout << "NO";
	return 0;
}