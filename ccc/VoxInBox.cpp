#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 1001;

int n;
char c[MAXN];
int g[MAXN][MAXN];

int hMap[6] = { 0, 1, 2, 4, 3, 5 }, vMap[6] = { 0, 2, 1, 4, 3, 5 }, dMap[6] = {
		0, -1, -1, 3, 4, 5 };

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c + 1;
		for (int j = 1; j <= n; j++) {
			if (c[j] == '(')
				g[i][j] = 1;
			else if (c[j] == ')')
				g[i][j] = 2;
			else if (c[j] == '/')
				g[i][j] = 3;
			else if (c[j] == '\\')
				g[i][j] = 4;
			else if (c[j] == '.')
				g[i][j] = 5;
		}
	}

	bool h = 1, v = 1, d1 = 1, d2 = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (g[i][j] != hMap[g[n + 1 - i][j]])
				h = 0;
			if (g[i][j] != vMap[g[i][n + 1 - j]])
				v = 0;
			if (g[i][j] != dMap[g[j][i]])
				d1 = 0;
			if (g[i][j] != dMap[g[n + 1 - j][n + 1 - i]])
				d2 = 0;
		}

	cout << h + v + d1 + d2;
}
