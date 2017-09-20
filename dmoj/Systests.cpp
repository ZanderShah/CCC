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
#include <unordered_set>
#include <map>
#include <bitset>
#include <cstdio>
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
typedef unordered_map<int, int> umii;

const int MAXN = 1e5 + 5;
int B, F;
ll b[MAXN][3], f[MAXN], s;

int main () {
	scanf("%d", &B);
	for (int i = 0; i < B; i++) {
		scanf("%d %d %d", &b[i][0], &b[i][1], &b[i][2]);
	}
	scanf("%d", &F);
	for (int i = 0; i < F; i++) {
		scanf("%d", &f[i]);
	}
	sort(f, f + F);
	for (int i = 0; i < B; i++) {
		int lo = 0, hi = F - 1;
		while (lo <= hi) {
			if (f[(lo + hi) / 2] < b[i][0]) {
				lo = (lo + hi) / 2 + 1;
			} else {
				hi = (lo + hi) / 2 - 1;
			}
		}
		s += f[lo] >= b[i][0] && f[lo] <= b[i][1] ? 0 : b[i][2];
	}
	printf("%lld\n", s);
}
