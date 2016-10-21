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

int S, N, Q;
vector<pair<pii, int> > v;

int main() {
	scanf("%d", &S);
	scanf("%d", &N);
	for (int i = 1, b, d, c; i <= N; i++) {
		scanf("%d %d %d", &b, &d, &c);
		if (b >= S)
			v.pb(mp(mp(b, c), i));
		else
			v.pb(mp(mp(b, d), i));
	}
	sort(v.begin(), v.end());
	scanf("%d", &Q);
	for (int i = 0, x; i < Q; i++) {
		scanf("%d", &x);
		printf("%d\n", v[N - x].y);
	}
}
