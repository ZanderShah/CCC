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
#include <unordered_set>

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

struct State {
	int id, period, swap;
	State(int i, int p, int s) {
		id = i;
		period = p;
		swap = s;
	}
};

int N, nerd, girl, p, s, id, county[505];
// [period][class in period]
unordered_set<int> classes[505][505];
int dp[505][505];
vector<pii> starting;
queue<State> q;
pii best = mp(505, 0);

int main() {
	scanf("%d", &N);
	scanf("%d %d", &nerd, &girl);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &p, &s);
		for (int j = 0; j < s; j++) {
			scanf("%d", &id);
			classes[p][county[p]].insert(id);
			if (id == nerd)
				q.push(State(id, p, 0));
		}
		county[p]++;
	}

	for (int i = 0; i < 505; i++)
		for (int j = 0; j < 505; j++)
			dp[i][j] = 505;

	while (!q.empty()) {
		State s = q.front();
		q.pop();

		if (s.swap >= best.x)
			continue;

		int clas = -1;
		for (int i = 0; i < county[s.period]; i++)
			if (classes[s.period][i].find(s.id) != classes[s.period][i].end())
				clas = i;

		if (clas != -1) {
			if (dp[s.period][clas] <= s.swap)
				continue;
			dp[s.period][clas] = s.swap;
		}

		if (clas != -1) {
			for (auto i = classes[s.period][clas].begin();
					i != classes[s.period][clas].end(); i++) {
				if (*i == girl) {
					if (best.x > s.swap + 1)
						best = mp(s.swap + 1, s.period);
					else if (best.x == s.swap + 1) {
						best.y = min(best.y, s.period);
					}
				} else if (*i != nerd) {
					q.push(State(*i, s.period + 1, s.swap + 1));
				}
			}
		}

		if (s.period < 500)
			q.push(State(s.id, s.period + 1, s.swap));
	}

	if (best.x == 505)
		printf("delivery failure");
	else
		printf("%d\n%d", best.x, best.y);
}
