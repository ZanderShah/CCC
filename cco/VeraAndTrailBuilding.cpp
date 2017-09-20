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

const int MAXN = 5005, V = 4750;

ll K;
int E = 0;
bool adj[MAXN][MAXN];

void solve() {
	for (int i = 1; i < V && K != 0; i++) {
		int j = i + 1;
		ll paths = 1;
		while (paths + (j - i + 1) <= K) {
			paths += j - i + 1;
			j++;
		}
		K -= paths;
		adj[j][i] = 1;
		i = j;
	}
}

int main() {
	scanf("%lld", &K);
	for (int i = 2; i <= V; i++) {
		adj[i - 1][i] = 1;
		E++;
	}
	solve();
	for (int i = 2; i <= V; i++) {
		for (int j = 1; j < i; j++) {
			if (adj[i][j]) {
				E++;
			}
		}
	}
	printf("%d %d\n", V, E);
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (adj[i][j]) {
				printf("%d %d\n", i, j);
			}
		}
	}
}
