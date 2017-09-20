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

int N, p[] = { 1, 2, 3, 4, 5, 6, 7, 8 }, g[9][9];
bool cube = 0;

int main() {
	scanf("%d", &N);
	for (int i = 0, x, y; i < N; i++) {
		scanf("%d %d", &x, &y);
		g[x][y] = g[y][x] = 1;
	}
	do {
		if (g[p[0]][p[1]] && g[p[0]][p[3]] && g[p[1]][p[2]] && g[p[2]][p[3]]
				&& g[p[0]][p[5]] && g[p[1]][p[4]] && g[p[2]][p[7]]
				&& g[p[3]][p[6]] && g[p[4]][p[5]] && g[p[4]][p[7]]
				&& g[p[5]][p[6]] && g[p[6]][p[7]])
			cube = 1;
	} while (next_permutation(p, p + 8));
	printf("%s", cube ? "Ja" : "Nej");
}
