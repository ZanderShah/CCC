#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x)                         \
	do { while ((x = getchar()) < '0') ;  \
	     for (x -= '0'; '0' <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - '0') ; } while (0)
char _;
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;

int d;
bool adj[26][26], vis[26];
string p;
vector<string> s;

bool dfs(int x) {
	if (x == 1) return 1;

	vis[x] = 1;

	bool ret = 0;

	for (int i = 0; i < 26; i++)
		if (!vis[i] && adj[x][i] && dfs(i)) ret = 1;
	return ret;
}

int main() {
	while (1) {
		cin >> p;

		if (p[0] == '*') break;
		s.pb(p);
		adj[p[0] - 'A'][p[1] - 'A'] = 1;
		adj[p[1] - 'A'][p[0] - 'A'] = 1;
	}

	d = 0;

	for (int i = 0; i < s.size(); i++) {
		adj[s[i][0] - 'A'][s[i][1] - 'A'] = 0;
		adj[s[i][1] - 'A'][s[i][0] - 'A'] = 0;

		for (int j = 0; j < 26; j++) vis[j] = 0;

		if (!dfs(0)) {
			cout << s[i] << endl;
			d++;
		}

		adj[s[i][0] - 'A'][s[i][1] - 'A'] = 1;
		adj[s[i][1] - 'A'][s[i][0] - 'A'] = 1;
	}

	printf("There are %d disconnecting roads.", d);
}
