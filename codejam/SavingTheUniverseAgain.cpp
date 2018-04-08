#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <deque>
#include <unordered_map>
#include <map>
#include <bitset>
#include <string>
#include <cstring>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do {while((x=getchar())<'0') ; for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0') ; } while(0)
char _;
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;

int T, D, s;
string P;

bool safe()
{
    int d = 0, c = 1;
    for (int i = 0; i < P.length(); ++i)
    {
        if (P[i] == 'C')
            c <<= 1;
        else
            d += c;
    }
    return d <= D;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> D >> P;
        s = 0;

        while (!safe())
        {
            ++s;
            bool change = false;
            for (int i = P.size() - 1; i >= 1 && !change; --i)
            {
                if (P[i] == 'S' && P[i - 1] == 'C')
                {
                    swap(P[i], P[i - 1]);
                    change = true;
                }
            }

            if (!change)
                break;
        }

        cout << "Case #" << t << ": ";
        if (safe())
            cout << s << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
}
