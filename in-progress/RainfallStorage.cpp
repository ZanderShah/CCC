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

int N, h[505];
bool vis[505][55][55 * 505];

void rain(int i, int j, int v) {
	if (vis[i][j][v]) {
		return;
	}

	vis[i][j][v] = 1;

	if (i == N - 1) {
		return;
	}

	for (int k = 0; k < N - 1; k++) {
		rain(i + 1, max(j, h[k]), v + max(0, j - h[k]));
	}
}

// 5
// 5 1 4 1 5
//
// 0 1 3 4 5 6 7 8 9

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &h[i]);
	}
	sort(h, h + N);

	for (int i = 0; i < N; i++) {
		rain(1, h[i], 0);
	}

	for (int i = 0; i < 55 * 505; i++) {
		for (int j = 0; j < 55; j++) {
			if (vis[N - 1][j][i]) {
				printf("%d ", i);
				break;
			}
		}
	}
}
