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

const int MAXN = 1e5 + 5;
int n, m;
bool included[MAXN];
vector<int> gnomes, missing;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0, g; i < m; ++i)
    {
        scanf("%d", &g);
        gnomes.pb(g);
        included[g] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!included[i])
            missing.pb(i);
    }
    int i = 0, j = 0;
    while (i < gnomes.size() || j < missing.size())
    {
        if (j < missing.size() && (i == gnomes.size() || missing[j] < gnomes[i]))
            printf("%d\n", missing[j++]);
        else
            printf("%d\n", gnomes[i++]);
    }
}
