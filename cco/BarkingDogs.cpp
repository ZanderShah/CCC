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

const int MAXN = 1e3 + 5;
int D, W[MAXN], F, T, bark[MAXN], busy[MAXN];
vector<int> adj[MAXN];
priority_queue<pii> cd;

int main() {
	scanf("%d", &D);
	for (int i = 1; i <= D; i++)
		scanf("%d", &W[i]);
	scanf("%d", &F);
	for (int i = 1, u, v; i <= F; i++) {
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
	}
	scanf("%d", &T);
	cd.push(mp(0, 1));
	while (!cd.empty()) {
		pii d = cd.top();
		cd.pop();
		d.x = -d.x;
		if (d.x > T)
			break;
		bark[d.y]++;
		for (int i = 0; i < adj[d.y].size(); i++) {
			if (busy[adj[d.y][i]] <= d.x) {
				busy[adj[d.y][i]] = d.x + W[adj[d.y][i]] + 1;
				cd.push(mp(-busy[adj[d.y][i]] + 1, adj[d.y][i]));
			}
		}
	}
	for (int i = 1; i <= D; i++)
		printf("%d\n", bark[i]);
}
