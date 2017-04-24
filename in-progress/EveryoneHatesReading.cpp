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

const int MAXN = 100005;

int N, M, trie[MAXN][26], c = 1;
string w[MAXN];

struct Query {
	string s;
	int x, c, i;

	bool operator < (const Query q) const {
		return x < q.x;
	}
} q[2 * MAXN];

int query(int i, int j, int k) {
	if (w[i].length() == j) {
		return 0;
	}
	if (trie[c][w[i][j] - 'a'] == 0) {
		return 0;
	} else {
		return 1 + query(i, j + 1, trie[c][w[i][j] - 'a']);
	}
}

void insert(int i, int j, int k) {
	if (w[i].length() == j) {
		return;
	}
	if (trie[c][w[i][j] - 'a'] == 0) {
		trie[c][w[i][j] - 'a'] = c;
		c++;
		insert(i, j + 1, k - 1);
	} else {
		insert(i, j + 1, trie[c][w[i][j] - 'a']);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < M; i++) {
		q[2 * i].i = q[2 * i + 1].i = i;

		q[2 * i].c = -1;
		q[2 * i + 1].c = 1;

		cin >> q[2 * i].s >> q[2 * i].x;
		q[2 * i].x--;

		q[2 * i + 1].s = q[2 * i].s;
		cin >> q[2 * i + 1].x;
	}
	sort(q, q + 2 * M);

	for (int i = 0; i < N; i++) {
		insert(i, 0, 0);
	}
}
