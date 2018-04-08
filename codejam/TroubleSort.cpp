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
int T, N, V[MAXN], V0[MAXN], V1[MAXN];

int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d", &N);

        for (int i = 0; i < N; ++i)
        {
            if (i & 1)
                scanf("%d", &V1[i >> 1]);
            else
                scanf("%d", &V0[i >> 1]);
        }
        sort(V0, V0 + (N + 1) / 2);
        sort(V1, V1 + N / 2);

        for (int i = 0; i < N; ++i)
        {
            if (i & 1)
                V[i] = V1[i >> 1];
            else
                V[i] = V0[i >> 1];
        }

        int err = -1;
        for (int i = 0; i < N - 1 && err == -1; ++i)
        {
            if (V[i] > V[i + 1])
                err = i;
        }

        if (err == -1)
            printf("Case #%d: OK\n", t);
        else
            printf("Case #%d: %d\n", t, err);
    }
}
