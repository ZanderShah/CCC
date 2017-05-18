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

const int MAXN = 105;

int N, M, g[MAXN][MAXN];

int main() {
	scanf("%d %d", &N, &M);

	bool early = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &g[i][j]);
			early &= g[i][j] == N * i + j;
		}
	}

	if (early) {
		printf("0\n");
		return 0;
	}

	if (N == 1 || M == 1) {
		printf("1\n");
		printf("%d 1 %d\n",(N == 1 ? 1 : 2), g[0][0]);
		return 0;
	}

	if (N * M <= 8) {

	}

	// Options
	int fullyBadRows = 0;

	for (int i = 0; i < N; i++) {
		int errors = 0;
		for (int j = 0; j < M; j++) {
			errors += g[i][j] != N * i + j;
		}

		if (errors == M) {
			fullyBadRows++;
		}
	}

	int fullyBadColumns = 0;

	for (int j = 0; j < M; j++) {
		int errors = 0;
		for (int i = 0; i < N; i++) {
			errors += g[i][j] != N * i + j;
		}
		if (errors == N) {
			fullyBadColumns++;
		}
	}
}
