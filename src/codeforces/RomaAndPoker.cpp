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

int n, k;
bool vis[1005][2005];
char s[1005];
bool leave;

void go(int i, int j) {
	if (i == n) {
		if (j == 0 || j == 2 * k) {
			printf("%s\n", s);
			leave = 1;
		}
		return;
	}
	if (j <= 0 || j >= 2 * k) {
		return;
	}
	if (vis[i][j] || leave) {
		return;
	}
	vis[i][j] = 1;

	if (s[i] == 'W') {
		go(i + 1, j + 1);
	} else if (s[i] == 'L') {
		go(i + 1, j - 1);
	} else if (s[i] == 'D') {
		go(i + 1, j);
	} else {
		s[i] = 'W';
		go(i + 1, j + 1);
		s[i] = 'L';
		go(i + 1, j - 1);
		s[i] = 'D';
		go(i + 1, j);
		s[i] = '?';
	}
}

int main() {
	scanf("%d %d", &n, &k);
	scanf(" %s", s);
	go(0, k);

	if (!leave) {
		printf("NO\n");
	}
}
