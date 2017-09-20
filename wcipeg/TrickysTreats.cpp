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

int N, M, T, best;
pii treats[100001];
priority_queue<int> pq;

int main() {
	scanf("%d %d %d", &N, &M, &T);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &treats[i].x, &treats[i].y);
	sort(treats, treats + N);

	int dist = 0, taken = 0, score = 0;
	for (int i = 0; i < N; i++) {
		dist = treats[i].x;
		taken++;
		score += treats[i].y;
		pq.push(-treats[i].y);
		while (!pq.empty() && dist * 2 + T * taken > M) {
			taken--;
			score += pq.top();
			pq.pop();
		}
		best = max(best, score);
	}

	printf("%d", best);
}
