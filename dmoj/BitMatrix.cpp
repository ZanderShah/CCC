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

int N, M;
vector<int> gen[10];

int main() {
	gen[0].pb(0);
	gen[0].pb(1);
	for (int i = 1; i < 10; i++) {
		bool flip = 0;
		for (int j = 0; j < gen[i - 1].size(); j++) {
			int x = l(gen[i - 1][j]), y = r(gen[i - 1][j]);
			if (flip) {
				swap(x, y);
			}
			gen[i].pb(x);
			gen[i].pb(y);
			flip ^= 1;
		}
	}

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", gen[9][i] << 10 | gen[9][j]);
		}
		printf("\n");
	}
}
