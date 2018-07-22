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

int T, K, N, L[2005], R[2005];
vector<int> pre_trav, post_trav;
umii compressed;

struct DisjointSet {
	struct Node {
		int p, sz;
		Node(int p) : p(p), sz(1) {}
	};

	int N;
	vector<Node> v;

	DisjointSet(int N) : N(N) {
		for (int i = 0; i <= N; i++)
			v.pb(Node(i));
	}
	int find(int x) {
		if (v[x].p != x)
			v[x].p = find(v[x].p);
		return v[x].p;
	}
	void merge(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y)
			return;

		if (v[x].sz > v[y].sz) {
			v[x].sz += v[y].sz;
			v[y].p = x;
		} else {
			v[y].sz += v[x].sz;
			v[x].p = y;
		}
	}
};

void pre(int i) {
    if (i == 0) {
        return;
    }
    assert(1 <= i && i <= N);
    pre_trav.push_back(i);
    pre(L[i]);
    pre(R[i]);
}
void post(int i) {
    if (i == 0) {
        return;
    }
    assert(1 <= i && i <= N);
    post(L[i]);
    post(R[i]);
    post_trav.push_back(i);
}

void test_pre(int i) {
    if (i == 0) {
        return;
    }
    pre_trav.push_back(compressed[i]);
    test_pre(L[i]);
    test_pre(R[i]);
}
void test_post(int i) {
    if (i == 0) {
        return;
    }
    test_post(L[i]);
    test_post(R[i]);
    post_trav.push_back(compressed[i]);
}

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d %d", &N, &K);
        for (int i = 1; i <= N; ++i) {
            scanf("%d %d", &L[i], &R[i]);
        }

        pre_trav.clear();
        post_trav.clear();
        compressed.clear();

        pre(1);
        post(1);

        DisjointSet ds(N);
        for (int i = 0; i < N; ++i) {
            ds.merge(pre_trav[i], post_trav[i]);
        }

        for (int i = 1, j = 1; i <= N; ++i) {
            if (compressed.find(ds.find(i)) == compressed.end()) {
                compressed[ds.find(i)] = min(j++, K);
            }
        }

        printf("Case #%d:", t);
        if (compressed.size() < K) {
            printf(" Impossible\n");
        } else {
            for (int i = 1; i <= N; ++i) {
                compressed[i] = compressed[ds.find(i)];
                printf(" %d", compressed[ds.find(i)]);
            }
            printf("\n");

            pre_trav.clear();
            post_trav.clear();
            test_pre(1);
            test_post(1);
            for (int i = 0; i < N; ++i) {
                assert(pre_trav[i] == post_trav[i]);
            }
        }
    }
}