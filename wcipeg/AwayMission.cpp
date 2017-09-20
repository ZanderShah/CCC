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
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;

const int MAXN = 200005;
int N, Q, r[MAXN], g[MAXN], b[MAXN], a;
vector<int> counterRed;

int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; i++)
		scanf("%d", &r[i]);
	for (int i = 0; i < N; i++) {
		scanf("%d", &g[i]);
		counterRed.pb(g[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
		counterRed.pb(b[i]);
	}
	sort(r, r + N);
	sort(g, g + N);
	sort(b, b + N);
	sort(counterRed.begin(), counterRed.end());
	if (Q == 1) {
		a = N;
		for (int i = N - 1, j = counterRed.size() - 1; i >= 0; i--, j--) {
			while (i >= 0 && r[i] > counterRed[j])
				i--;
			if (i >= 0)
				a--;
		}
	} else {
		a = 0;
		for (int i = N - 1, j = N - 1, k = N - 1; i >= 0; i--, j--, k--) {
			while (j >= 0 && g[j] >= r[i])
				j--;
			while (k >= 0 && b[k] >= r[i])
				k--;
			if (j >= 0 && k >= 0)
				a++;
		}
	}
	printf("%d\n", a);
}
