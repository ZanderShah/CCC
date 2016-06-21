#include <bits/stdc++.h>
using namespace std;

int n;
string s = "";

int main()
{
	for (int i = 1, x; i < 500; i++)
		s += to_string(i);
	
	cin >> n;
	cout << s[n - 1];
	return 0;
}