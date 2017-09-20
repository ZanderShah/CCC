#include <bits/stdc++.h>
using namespace std;

int n, k, m, p[101];

int main() 
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> p[i];

    int t = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0, x, v; j < m; j++)    
        {
            cin >> v;

            for (int a = 1; a <= k; a++)
            {
                if (p[a] == v)
                    x = a;
            }

            t += x;
            p[0] = p[x];

            for (int a = x; a >= 1; a--)
                p[a] = p[a - 1];
        }

    cout << t;
    return 0;
}
