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

const int MAXN = 2e6 + 5;

int N;
pii n[MAXN];
bool vis[MAXN];
priority_queue<int> paid;
queue<pii> hold;

int main() {
	scanf("%d", &N);
	for (int i = 0, a, b; i < N; i++) {
		scanf("%d %d", &a, &b);
		n[i] = (mp(a, b));
	}
	sort(n, n + N);

	ll cost = 0;

	for (int i = 0; i < N; i++) {
		while (!hold.empty() && hold.front().x <= i) {
			paid.push(hold.front().y);
			hold.pop();
		}

		if (n[i].x <= i) {
			// Pay if its value
			if (!paid.empty() && paid.top() > n[i].y) {
				cost += n[i].y - paid.top();
				paid.pop();
				hold.push(n[i]);
			}
		} else {
			// Have to pay
			cost += n[i].y;
			// Can take out one person with Ai < i
			if (!paid.empty()) {
				cost -= paid.top();
				paid.pop();
			}

			hold.push(n[i]);
		}
	}

	printf("%lld\n", cost);
}
