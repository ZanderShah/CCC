#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

struct Lightbulb {
	int i, j, w;
	Lightbulb(int ii, int jj, int ww) {
		i = ii;
		j = jj;
		w = ww;
	}
};

struct Ask {
	int x1, y1, x2, y2;
	Ask(int xx1, int yy1, int xx2, int yy2) {
		x1 = xx1;
		y1 = yy1;
		x2 = xx2;
		y2 = yy2;
	}
};

int n, m, k, q;
char c[20];
ll bit[2001][2001], ans[2001];
vector<Lightbulb> lights[2001];
vector<Ask> ask;
bool off[2001][2001], current[2001];

void update(int x, int y, int w) {
	for (; x <= n; x += x & -x)
		for (int j = y; j <= m; j += j & -j)
			bit[x][j] += w;
}

ll query(int x, int y) {
	ll ret = 0;
	for (; x; x -= x & -x)
		for (int j = y; j; j -= j & -j)
			ret += bit[x][j];
	return ret;
}

int main() {
	scan(n);
	scan(m);
	scan(k);

	// Store garland info
	for (int i = 1, l; i <= k; i++) {
		scan(l);
		for (int j = 1, x, y, w; j <= l; j++) {
			scan(x);
			scan(y);
			scan(w);
			lights[i].pb(Lightbulb(x, y, w));
		}
	}

	// Store query info
	scanf("%d", &q);
	for (int i = 0, j, x1, y1, x2, y2; i < q; i++) {
		scanf("%s ", c);
		if (c[0] == 'A') {
			scan(x1);
			scan(y1);
			scan(x2);
			scan(y2);
			ask.pb(Ask(x1, y1, x2, y2));
			memcpy(off[ask.size() - 1], current, sizeof current);
		} else {
			scan(j);
			current[j] ^= 1;
		}
	}

	// Load up each garland and compute partial answer to all queries
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < lights[i].size(); j++)
			update(lights[i][j].i, lights[i][j].j, lights[i][j].w);
		for (int j = 0; j < ask.size(); j++)
			if (!off[j][i])
				ans[j] += query(ask[j].x2, ask[j].y2)
						+ query(ask[j].x1 - 1, ask[j].y1 - 1)
						- query(ask[j].x1 - 1, ask[j].y2)
						- query(ask[j].x2, ask[j].y1 - 1);
		// Faster than memset clear
		for (int j = 0; j < lights[i].size(); j++)
			update(lights[i][j].i, lights[i][j].j, -lights[i][j].w);
	}

	for (int i = 0; i < ask.size(); i++)
		printf("%I64d\n", ans[i]);
}
