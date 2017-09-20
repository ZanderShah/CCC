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
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;

int N, D, c;
string s;
vector<pii> room;

int main() {
	scanf("%d %d", &N, &D);
	cin >> s;
	s = s + "#";
	for (int i = 0, l; i < s.length(); i++)
		if (s[i] == '.') {
			l = i;
			while (s[i + 1] == '.')
				i++;
			room.pb(mp(l, i));
		}
	for (int i = 0, l; i < room.size(); c++, i++) {
		l = i;
		while (i + 1 < room.size() && room[i + 1].x - D <= room[l].y)
			i++;
		l = i;
		while (i + 1 < room.size() && room[l].y + D >= room[i + 1].x)
			i++;
	}
	printf("%d", c);
}
