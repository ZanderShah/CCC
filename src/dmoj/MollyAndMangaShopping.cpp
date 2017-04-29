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

int N, a[MAXN], Q, size, freq[MAXN], even = 0, ans[MAXN];

struct Query {
	int i, l, r;
	bool operator< (const Query &q) const {
		if (l / size == q.l / size) {
			return r < q.r;
		}
		return l < q.l;
	}
} q[MAXN];

int main() {
	scanf("%d", &N);
	size = sqrt(N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].i = i;
	}
	sort(q, q + Q);

	for (int i = 0, l = 0, r = 0; i < Q; i++) {
		while (l < q[i].l) {
			freq[a[l]]--;
			if (freq[a[l]] > 0) {
				even += freq[a[l]] & 1 ? -1 : 1;
			}
			l++;
		}
		while (l > q[i].l) {
			l--;
			freq[a[l]]++;
			if (freq[a[l]] > 1) {
				even += freq[a[l]] & 1 ? -1 : 1;
			}
		}
		while (r < q[i].r) {
			r++;
			freq[a[r]]++;
			if (freq[a[r]] > 1) {
				even += freq[a[r]] & 1 ? -1 : 1;
			}
		}
		while (r > q[i].r) {
			freq[a[r]]--;
			if (freq[a[r]] > 0) {
				even += freq[a[r]] & 1 ? -1 : 1;
			}
			r--;
		}

		ans[q[i].i] = even;
	}

	for (int i = 0; i < Q; i++) {
		printf("%d\n", ans[i]);
	}
}
