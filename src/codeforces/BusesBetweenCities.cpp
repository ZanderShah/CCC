#include <bits/stdc++.h>
using namespace std;

int a, ta, b, tb, d;
string s;

int main() 
{
    cin >> a >> ta;
    cin >> b >> tb;
    cin >> s;

    d = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));

    int ans = 0;

    for (int t = 5 * 60; t < 24 * 60; t += b)
        if (t + tb > d && t < d + ta)
            ans++;

    cout << ans;
    return 0;
}
