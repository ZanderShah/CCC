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
typedef pair<ll, ll> pll;

struct Node {
	int r, p;
	Node(int pp) {
		r = 0;
		p = pp;
	}
};

vector<Node> v;

int find(int x) {
	if (v[x].p != x)
		v[x].p = find(v[x].p);
	return v[x].p;
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)
		return;

	if (v[x].r < v[y].r)
		v[x].p = y;
	else if (v[x].r > v[y].r)
		v[y].p = x;
	else {
		v[y].p = x;
		v[x].r++;
	}
}

int N, M, K, x, y;
vector<int> ans;

int main() {
	scan(N);
	scan(M);
	v.push_back(Node(0));
	for (int i = 1; i <= N; i++)
		v.push_back(Node(i));
	for (int i = 1; i <= M; i++) {
		scan(K);
		if (K) {
			scan(x);
			for (int i = 1; i < K; i++) {
				scan(y);
				merge(x, y);
			}
		}
	}
	for (int i = 1; i <= N; i++)
		if (find(1) == find(i))
			ans.pb(i);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
}
