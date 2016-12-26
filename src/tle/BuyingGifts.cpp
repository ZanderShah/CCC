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

int S, N, T, p[5][1005], to[1005], mtt, t[1005][5], maxs[5], nc;
bool sm;
pii tt[1005];
priority_queue<int> pq;

int go(int k, int y) {
	int ret = 1e9;

	for (int i = 0; i < T; i++)
		maxs[i] = 0;
	for (int i = 0; i < S; i++) {
		if ((y >> i) & 1) {
			for (int j = 0; j < T; j++)
				maxs[j] = max(maxs[j], t[i][j]);
		}
	}
	nc = 0;
	for (int i = 0; i < S; i++) {
		sm = 1;
		for (int j = 0; j < T; j++)
			if (t[i][j] > maxs[j])
				sm = 0;
		nc += sm;
	}

	if (nc >= N) {
		ret = 0;
		for (int i = 0; i < T; i++)
			ret += maxs[i] * N;
	}

	if (__builtin_popcount(y) < T)
		for (int i = k + 1; i < S; i++)
			ret = min(ret, go(i, y | 1 << i));
	return ret;
}

int main() {
	scanf("%d %d %d", &S, &N, &T);
	if (T == 1) {
		for (int i = 0; i < S; i++)
			scanf("%d", &to[i]);
		sort(to, to + S);
		printf("%d\n", to[N - 1] * N);
	} else if (T == 2) {
		for (int i = 0; i < S; i++)
			scanf("%d %d", &tt[i].x, &tt[i].y);
		sort(tt, tt + S);

		// Assuming we are first taking the N lowest T1
		for (int i = 0; i < N; i++)
			pq.push(tt[i].y);
		mtt = pq.top() * N + tt[N - 1].x * N;

		// Can give up the worst T1 to take a possibly better T2
		for (int i = N; i < S; i++) {
			pq.push(tt[i].y);
			pq.pop();
			mtt = min(mtt, pq.top() * N + tt[i].x * N);
		}
		printf("%d\n", mtt);
	} else {
		for (int i = 0; i < S; i++)
			for (int j = 0; j < T; j++)
				scanf("%d", &t[i][j]);
		printf("%d\n", go(-1, 0));
	}
}
