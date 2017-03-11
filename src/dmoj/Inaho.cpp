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
#include <cstdio>
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
typedef unordered_map<int, int> umii;

struct Node {
	int p, sz;
};
vector<Node> v;
stack<pii> s;

int find(int x) {
	if (v[x].p != x) {
		return find(v[x].p);
	}
	return v[x].p;
}

void merge(int x, int y) {
	if (x == y) {
		return;
	}
	if (v[x].sz < v[y].sz) {
		v[y].sz += v[x].sz;
		v[x].p = y;
	} else {
		v[x].sz += v[y].sz;
		v[y].p = x;
	}
}

void unmerge(int x, int y) {
	if (x == y) {
		return;
	}
	if (v[x].sz < v[y].sz) {
		v[y].sz -= v[x].sz;
		v[x].p = x;
	} else {
		v[x].sz -= v[y].sz;
		v[y].p = y;
	}
}

void Init(int N) {
	for (int i = 0; i <= N; i++) {
		v.pb(Node {i, 1});
	}
}

void AddEdge(int x, int y) {
	x = find(x);
	y = find(y);
	s.push(mp(x, y));
	merge(x, y);
}

void RemoveLastEdge() {
	unmerge(s.top().x, s.top().y);
	s.pop();
}

int GetSize(int x) {
	return v[find(x)].sz;
}

int main() {

}
