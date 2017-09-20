#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define FILE 1
using namespace std;

typedef long long ll;

const int MAXN = 2000001, MOD = 1000000007;

int n, ind[MAXN], x[MAXN], y[MAXN];
ll horses[MAXN];
double logHorses[MAXN], money[MAXN], lazy[MAXN], precomputed[MAXN];

inline void pushUp(int node) {
	if (money[l(node)] > money[r(node)]) {
		money[node] = money[l(node)];
		ind[node] = ind[l(node)];
	} else {
		money[node] = money[r(node)];
		ind[node] = ind[r(node)];
	}
}

void buildMulti(int node, int left, int right) {
	if (left == right) {
		horses[node] = x[left - 1];
		return;
	}

	int mid = (left + right) / 2;
	buildMulti(l(node), left, mid);
	buildMulti(r(node), mid + 1, right);

	horses[node] = (horses[l(node)] * horses[r(node)]) % MOD;
}

void updateMulti(int node, int curLeft, int curRight, int left, int right) {
	if (curLeft > right || curRight < left)
		return;

	if (curLeft == left && curRight == right) {
		horses[node] = x[left - 1];
		return;
	}

	int mid = (curLeft + curRight) / 2;
	if (mid >= right)
		updateMulti(l(node), curLeft, mid, left, right);
	else if (mid < left)
		updateMulti(r(node), mid + 1, curRight, left, right);
	else {
		updateMulti(l(node), curLeft, mid, left, mid);
		updateMulti(r(node), mid + 1, curRight, mid + 1, right);
	}

	horses[node] = (horses[l(node)] * horses[r(node)]) % MOD;
}

ll fullQueryMulti(int node, int curLeft, int curRight, int left, int right) {
	if (curLeft == left && curRight == right)
		return horses[node];

	int mid = (curLeft + curRight) / 2;
	if (mid >= right)
		return fullQueryMulti(l(node), curLeft, mid, left, right);
	else if (mid < left)
		return fullQueryMulti(r(node), mid + 1, curRight, left, right);
	else
		return fullQueryMulti(l(node), curLeft, mid, left, mid)
				* fullQueryMulti(r(node), mid + 1, curRight, mid + 1, right)
				% MOD;
}

void buildMoney(int node, int left, int right) {
	if (left == right) {
		money[node] = precomputed[left] + log2(y[left - 1]);
		ind[node] = left;
		return;
	}

	int mid = (left + right) / 2;
	buildMoney(l(node), left, mid);
	buildMoney(r(node), mid + 1, right);

	pushUp(node);
}

void updateMoney(int node, int curLeft, int curRight, int left, int right,
		double delta) {
	if (curLeft == left && curRight == right) {
		money[node] += delta;
		lazy[node] += delta;
		return;
	}

	if (lazy[node]) {
		money[l(node)] += lazy[node];
		money[r(node)] += lazy[node];
		lazy[l(node)] += lazy[node];
		lazy[r(node)] += lazy[node];
		lazy[node] = 0;
	}

	int mid = (curLeft + curRight) / 2;
	if (mid >= right)
		updateMoney(l(node), curLeft, mid, left, right, delta);
	else if (mid < left)
		updateMoney(r(node), mid + 1, curRight, left, right, delta);
	else {
		updateMoney(l(node), curLeft, mid, left, mid, delta);
		updateMoney(r(node), mid + 1, curRight, mid + 1, right, delta);
	}

	pushUp(node);
}

int init(int N, int X[], int Y[]) {
	n = N;

	for (int i = 0; i < n; i++) {
		x[i] = X[i];
		y[i] = Y[i];
		precomputed[i + 1] = log2(x[i]) + precomputed[i];
	}

	buildMulti(1, 1, n);
	buildMoney(1, 1, n);

	return fullQueryMulti(1, 1, n, 1, ind[1]) * y[ind[1] - 1] % MOD;
}

int updateX(int pos, int val) {
	updateMoney(1, 1, n, pos + 1, n, log2(val) - log2(x[pos]));

	x[pos] = val;
	updateMulti(1, 1, n, pos + 1, pos + 1);

	return fullQueryMulti(1, 1, n, 1, ind[1]) * y[ind[1] - 1] % MOD;
}

int updateY(int pos, int val) {
	updateMoney(1, 1, n, pos + 1, pos + 1, log2(val) - log2(y[pos]));
	y[pos] = val;

	return fullQueryMulti(1, 1, n, 1, ind[1]) * y[ind[1] - 1] % MOD;
}
