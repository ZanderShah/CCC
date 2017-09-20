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

const int DIR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
string D[4], S;
set<pii> dest;
unordered_map<int, unordered_map<int, unordered_map<int, bool> > > vis;

void ways(int i, int x, int y) {
	if (i == S.length()) {
		dest.insert(mp(x, y));
		return;
	}
	if (S.length() < i) {
		return;
	}
    if (vis[i][x].find(y) != vis[i][x].end()) {
        return;
    }

	for (int j = 0; j < 4; j++) {
		bool match = 1;
		for (int k = 0; k < D[j].length(); k++) {
			if (S.length() <= i + k || S[i + k] != D[j][k]) {
				match = 0;
			}
		}
		if (match) {
			ways(i + D[j].length(), x + DIR[j][0], y + DIR[j][1]);
		}
	}

    vis[i][x][y] = 1;
}

int main() {
	cin >> D[0] >> D[1] >> D[2] >> D[3] >> S;
	ways(0, 0, 0);
	printf("%d\n", dest.size());
}
