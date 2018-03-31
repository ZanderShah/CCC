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

struct BIT
{
	int N;
	vector<int> bit;

	BIT(int N) : N(N), bit(N + 1) {}

	void update(int x, int v)
    {
		for (; x <= N; x += x & -x)
			bit[x] += v;
	}

	int query(int x)
    {
		int ret = 0;
		for (; x; x -= x & -x)
			ret += bit[x];
		return ret;
	}
};

const int MAXN = 1e5 + 5;
int R, C;
BIT bit(MAXN);

pii r[MAXN], c[MAXN];
vector<pii> inc[MAXN];

bool connected = true;

int main()
{
    scanf("%d %d", &R, &C);

    for (int i = 1; i <= R; ++i)
    {
        scanf("%d %d", &r[i].x, &r[i].y);
        inc[r[i].x].pb(mp(i, 1));
        inc[r[i].y + 1].pb(mp(i, -1));

        if (i != 1 && (r[i - 1].y < r[i].x || r[i].y < r[i - 1].x))
            connected = false;
    }

    for (int i = 1; i <= C; ++i)
    {
        for (pii u : inc[i])
            bit.update(u.x, u.y);

        scanf("%d %d", &c[i].x, &c[i].y);

        int r_sum = bit.query(R);
        int enc_sum = bit.query(c[i].y) - bit.query(c[i].x - 1);

        if (r_sum != c[i].y - c[i].x + 1 || r_sum != enc_sum)
        {
            printf("nonsense\n");
            for (int j = 1; j <= R; ++j)
            {
                bool in_r = r[j].x <= i && i <= r[j].y;
                bool in_c = c[i].x <= j && j <= c[i].y;
                if (in_r ^ in_c)
                {
                    printf("%d %d\n", j, i);
                    break;
                }
            }
            return 0;
        }
    }

    if (!connected)
    {
        printf("nonsense\n");
        printf("unconnected\n");
    }
    else
    {
        printf("sense\n");
    }
}
