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

int F, N;
ll ee, d;
string s;
unordered_map<string, int> e;
vector<pii> f;

int main()
{
    cin >> F;
    for (int i = 0; i < F; ++i)
    {
        cin >> s >> ee;
        e[s] = ee;
    }
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> s >> d;
        f.pb(mp(d, e[s]));
    }
    sort(f.begin(), f.end());
    d = ee = 0;
    for (int i = 0; i < N; ++i)
    {
        ll c = f[i].x - d;
        if (ee < c && c != 0)
        {
            cout << i << endl;
            return 0;
        }
        d = f[i].x;
        ee += f[i].y - c;
    }
    cout << N << endl;
}
