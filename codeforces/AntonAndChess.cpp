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

int n, xx, yy, x, y;
ll dist[8];
char t, close[8];
bool check;

int main() {
	scanf("%d", &n);
	scanf("%d %d", &xx, &yy);
	for (int i = 0; i < 8; i++)
		dist[i] = 1ll << 60;
	// 0 1 2
	// 3 K 4
	// 5 6 7
	for (int i = 0; i < n; i++) {
		scanf(" %c %d %d", &t, &x, &y);
		if (x - xx == y - yy && x - xx < 0 && xx - x < dist[0]) {
			dist[0] = xx - x;
			close[0] = t;
		} else if (y - yy == 0 && x - xx < 0 && xx - x < dist[1]) {
			dist[1] = xx - x;
			close[1] = t;
		} else if (x - xx == yy - y && x - xx < 0 && xx - x < dist[2]) {
			dist[2] = xx - x;
			close[2] = t;
		} else if (x - xx == 0 && y - yy < 0 && yy - y < dist[3]) {
			dist[3] = yy - y;
			close[3] = t;
		} else if (x - xx == 0 && y - yy > 0 && y - yy < dist[4]) {
			dist[4] = y - yy;
			close[4] = t;
		} else if (x - xx == yy - y && x - xx > 0 && x - xx < dist[5]) {
			dist[5] = x - xx;
			close[5] = t;
		} else if (y - yy == 0 && x - xx > 0 && x - xx < dist[6]) {
			dist[6] = x - xx;
			close[6] = t;
		} else if (x - xx == y - yy && x - xx > 0 && x - xx < dist[7]) {
			dist[7] = x - xx;
			close[7] = t;
		}
	}

	for (int i = 0; i < 8; i++)
		if (close[i] == 'Q')
			check = 1;
	if (close[0] == 'B' || close[1] == 'R' || close[2] == 'B' || close[3] == 'R'
			|| close[4] == 'R' || close[5] == 'B' || close[6] == 'R'
			|| close[7] == 'B')
		check = 1;
	printf("%s", check ? "YES" : "NO");
}
