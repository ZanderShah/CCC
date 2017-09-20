#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 7;

int n;
vector<int> adj[MAXN];

bool dfs(int i, int x) {
	for (int j = 0; j < adj[i].size(); j++)
		if (!(x & 1 << adj[i][j]) || !dfs(adj[i][j], x))
			return false;
	return true;
}

bool validate(int x) {
	for (int i = 0; i < n - 1; i++)
		if (x & (1 << i))
			if (!dfs(i, x))
				return 0;
	return 1;
}

int generateSubsets(int i, int s) {
	if (i == n - 1)
		return validate(s);
	return generateSubsets(i + 1, s) + generateSubsets(i + 1, s + (1 << i));
}

int main() {
	scanf("%d", &n);
	for (int i = 0, x; i < n - 1; i++) {
		scanf("%d", &x);
		adj[x - 1].pb(i);
	}

	printf("%d", generateSubsets(0, 0));
}
