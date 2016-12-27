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

vector<pii> adj[100005];
vector<int> mls;
pii opt;
bool mark[100005];
char vis[100005];
int dia;

void dfs(int i, int l, int t) {
	if (opt.y < l)
		opt = mp(i, l);
	vis[i] = t;
	for (int j = 0; j < adj[i].size(); j++)
		if (vis[adj[i][j].x] != t)
			dfs(adj[i][j].x, l + adj[i][j].y, t);
}

int markPath(int a, int b) {
	if (a == b)
		return mark[a] = 1;
	vis[a] = 3;
	bool ret = 0;
	for (int i = 0; i < adj[a].size(); i++)
		if (vis[adj[a][i].x] != 3)
			ret |= markPath(adj[a][i].x, b);
	return mark[a] = ret;
}

int findMin(int a, int l) {
	int ret = max(l, opt.y - l);
	vis[a] = 4;
	for (int i = 0; i < adj[a].size(); i++)
		if (vis[adj[a][i].x] != 4 && mark[adj[a][i].x])
			ret = min(ret, findMin(adj[a][i].x, l + adj[a][i].y));
	return ret;
}

// N nodes, M edges, L length of inserted path, [A B T] edge
int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
	for (int i = 0; i < M; i++) {
		adj[A[i]].pb(mp(B[i], T[i]));
		adj[B[i]].pb(mp(A[i], T[i]));
	}
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			opt.y = -1;
			dfs(i, 0, 1);
			ll a = opt.x;
			opt.y = -1;
			dfs(a, 0, 2);
			dia = max(dia, opt.y);
			// Mark longest path
			markPath(a, opt.x);
			mls.pb(findMin(a, 0));
		}
	}
	sort(mls.begin(), mls.end());

	int ret = dia;

	int sz = mls.size();
	if (sz == 1)
		ret = max(ret, mls[0]);
	else if (sz == 2)
		ret = max(mls[0] + mls[1] + L, ret);
	else
		ret = max(ret,
				max(mls[sz - 1] + mls[sz - 2] + L,
						mls[sz - 2] + mls[sz - 3] + 2 * L));
	return ret;
}

// int N, M, L, A[100005], B[100005], T[100005];

// int main() {
// 	scanf("%d %d %d\n", &N, &M, &L);
// 	for (int i = 0; i < M; i++) {
// 		scanf("%d", &A[i]);
// 		scanf("%d", &B[i]);
// 		scanf("%d", &T[i]);
// 	}
// 	printf("%d\n", travelTime(N, M, L, A, B, T));
// }
