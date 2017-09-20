#include <bits/stdc++.h>
using namespace std;

int n, k, l[100], luck = 0;

int main() 
{
    cin >> n >> k;

    for (int i = 0, x, v; i < n; i++)
    {
    	cin >> x >> v;
    	if (v)
    		l[i] = x;
    	else
    		luck += x;
    }

    sort(l, l + n);

    for (int i = n - 1; i >= 0; i--)
    	if (k)
    	{
    		luck += l[i];
    		k--;
    	}
    	else
    	{
    		luck -= l[i];
    	}

    cout << luck;

    return 0;
}
