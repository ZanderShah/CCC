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

const int MAXN = 200005;

int N, c, C[MAXN], lvl = 0, last = -1, cards;
priority_queue<int> cur;
queue<pii> hold;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &c);
		hold.push(mp(i, c));
	}
	cur.push(-hold.front().y);
	hold.pop();

	// Always take the lowest value security card
	while (1) {
		while (!cur.empty() && -cur.top() <= last) {
			cur.pop();
		}
		if (cur.empty()) {
			break;
		}

		c = -cur.top();
		cur.pop();

		last = c;
		lvl += c;
		cards++;

		if (lvl >= N) {
			printf("%d\n", cards);
			return 0;
		}

		// Add new stuff to cur
		while (!hold.empty() && hold.front().x <= lvl) {
			cur.push(-hold.front().y);
			hold.pop();
		}
	}

	printf("-1\n");
}
