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

int N;
bool men[26], vis[26];
set<char> sets[26];
vector<int> adj[26];
char a, b;
string c;

void dfs(int x, int i) {
	vis[i] = 1;
	for (auto j = sets[i].begin(); j != sets[i].end(); j++) {
		sets[x].insert(*j);
	}
	for (int j = 0; j < adj[i].size(); j++) {
		if (!vis[adj[i][j]]) {
			dfs(x, adj[i][j]);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> a >> c >> b;
		if (islower(b)) {
			sets[a - 'A'].insert(b);
		} else {
			adj[a - 'A'].pb(b - 'A');
			men[b - 'A'] = 1;
		}
		men[a - 'A'] = 1;
	}
	for (int i = 0; i < 26; i++) {
		if (men[i]) {
			for (int j = 0; j < 26; j++) {
				vis[j] = 0;
			}
			dfs(i, i);
			cout << (char) ('A' + i) << " = {";
			for (auto j = sets[i].begin(); j != sets[i].end(); j++) {
				if (j == sets[i].begin()) {
					cout << *j;
				} else {
					cout << "," << *j;
				}
			}
			cout << "}" << endl;
		}
	}
}
