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

int N, T, t;
bool o[100005];

int main()
{
    cin >> N >> T;
    t = N;

    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
    {
        o[i + 1] = s[i] == '|';
        t += 2 * o[i + 1];
    }

    for (int i = 0, m; i < T; ++i)
    {
        cin >> m;
        t += o[m] ? -2 : 2;
        o[m] ^= 1;
        cout << (o[1] ? 1 : t) << endl;
    }
}
