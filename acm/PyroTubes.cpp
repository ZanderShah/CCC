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

bool L[500005];
vector<int> LL;

int main() {
    memset(L, false, sizeof L);
    while (1)
    {
        int l;
        scanf("%d", &l);
        if (l == -1)
            break;
        LL.pb(l);
        L[l] = true;
    }
    for (int i = 0; i < LL.size(); ++i)
    {
        int c = 0;
        for (int j = 0; j < 18; ++j)
        {
            // 1
            int l1 = LL[i] ^ (1ll << j);
            if (LL[i] < l1 && L[l1])
                c++;
            // 2
            for (int k = j + 1; k < 18; ++k)
            {
                int l2 = l1 ^ (1ll << k);
                if (LL[i] < l2 && L[l2])
                    c++;
            }
        }
        printf("%d:%d\n", LL[i], c);
    }
}
