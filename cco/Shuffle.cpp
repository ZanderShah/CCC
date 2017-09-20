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

vector<int> m[150];
char T[85];
int x, N;
bool vis[150][150];

void read(int c) {
	scanf(" %c", &x);
	m[c].pb(x);
	vis[c][x] = 1;
}

void cycle(int c, int l) {
	if (!vis[c][m[l][0]]) {
		m[c].pb(m[l][0]);
		vis[c][m[l][0]] = 1;
		cycle(c, m[l][0]);
	}
}

int main() {
	for (int i = 'A'; i <= 'Z'; i++)
		read(i);
	read('_');
	for (int i = 'A'; i <= 'Z'; i++)
		cycle(i, m[i][0]);
	cycle('_', m['_'][0]);

	scanf("%d", &N);
	N--;
	scanf(" %s", T);
	for (int i = 0; T[i]; i++)
		printf("%c", m[T[i]][N % m[T[i]].size()]);
}
