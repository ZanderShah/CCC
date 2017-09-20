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

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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
typedef unordered_map<int, int> umii;

const int MAXN = 2e5 + 5;
int n, m, k, x, s, low, up;
pii speed[MAXN], insta[MAXN];
ll best;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	scanf("%d %d", &x, &s);
	speed[0].x = x;
	best = -1;
	for (int i = 1; i <= m; i++)
		scanf("%d", &speed[i].x);
	for (int i = 1; i <= m; i++)
		scanf("%d", &speed[i].y);
	for (int i = 1; i <= k; i++)
		scanf("%d", &insta[i].x);
	for (int i = 1; i <= k; i++)
		scanf("%d", &insta[i].y);

	for (int i = 0; i <= m; i++)
		if (speed[i].y <= s) {
			low = 0;
			up = k;
			while (low <= up) {
				if (insta[(low + up) / 2].y <= s - speed[i].y)
					low = (low + up) / 2 + 1;
				else
					up = (low + up) / 2 - 1;
			}

			if (best == -1)
				best = (n - insta[up].x) * 1ll * speed[i].x;
			else
				best = min(best, (n - insta[up].x) * 1ll * speed[i].x);
		}

	printf("%lld\n", best);
}
