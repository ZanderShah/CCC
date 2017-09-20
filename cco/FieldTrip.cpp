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
typedef unordered_map<int, int> umii;

struct Node {
	int r, p, sz;
	bool c;
	Node(int pp) {
		r = 0;
		p = pp;
		sz = 1;
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

	if (x == y) {
		v[find(x)].c = 1;
		return;
	}

	if (v[x].r < v[y].r) {
		v[x].p = y;
		v[y].sz += v[x].sz;
	} else if (v[x].r > v[y].r) {
		v[y].p = x;
		v[x].sz += v[y].sz;
	} else {
		v[y].p = x;
		v[x].r++;
		v[x].sz += v[y].sz;
	}
}

int N, M, K, bus, cut;
bool vis[1000005];

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i <= N; i++)
		v.push_back(Node(i));
	for (int i = 0, u, v; i < M; i++) {
		scanf("%d %d", &u, &v);
		merge(u, v);
	}
	for (int i = 1; i <= N; i++) {
		if (!vis[find(i)]) {
			vis[find(i)] = 1;
			bus += v[find(i)].sz / K * K;
			cut += (v[find(i)].sz - 1) / K;
			if (cut)
				cut += v[find(i)].c;
		}
	}
	printf("%d %d\n", bus, cut);
}
