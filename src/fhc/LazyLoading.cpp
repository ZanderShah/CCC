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

int T, N, w[105], r[105], trips;

int main() {
	scanf("%d", &T);
	for (int c = 1; c <= T; c++) {
		scanf("%d", &N);
		trips = 0;

		for (int i = 0; i < N; i++) {
			scanf("%d", &w[i]);
		}
		sort(w, w + N);
		for (int i = 0; i < N; i++) {
			r[i] = ceil(50.0 / w[i]) - 1;
		}

		for (int i = 0, j = N - 1; j >= 0; j--) {
			if (j - i >= r[j]) {
				trips++;
				i += r[j];
			}
		}

		printf("Case #%d: %d\n", c, trips);
	}
}
