#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1 << 9, FLIP[9] = { 11, 23, 38, 89, 186, 308, 200, 464, 416 };

int P, vis[MAXN], state;
string s[3];
queue<pii> q;

void clean(queue<pii> &q) {
	queue<pii> empty;
	swap(q, empty);
}

int main() {
	cin >> P;

	for (int t = 0; t < P; t++) {
		clean(q);
		state = 0;
		for (int i = 0; i < (1 << 9); i++)
			vis[i] = 0;

		cin >> s[0] >> s[1] >> s[2];

		for (int i = 0; i < 9; i++)
			if (s[i / 3][i % 3] == '*')
				state += 1 << i;

		q.push(mp(state, 0));

		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();

			if (!x) {
				cout << y << endl;
				break;
			}

			vis[x] = 1;

			for (int i = 0; i < 9; i++)
				if (!vis[x ^ FLIP[i]])
					q.push(mp(x ^ FLIP[i], y + 1));
		}
	}

}
