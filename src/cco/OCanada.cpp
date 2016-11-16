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

int N, G;
char s[10];
bool c[10][10];
unordered_map<int, int> edge;

int main() {
	cin >> N >> G;
	for (int g = 0; g < G; g++) {
		for (int i = 0; i < N; i++) {
			cin >> s;
			for (int j = 0; j < N; j++)
				c[i][j] = s[j] == 'R';
		}
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < N - 1; j++) {
				if (c[i][j]) {
					c[i][j] ^= 1;
					c[i + 1][j] ^= 1;
					c[i][j + 1] ^= 1;
					c[i + 1][j + 1] ^= 1;
				}
			}
		}
		int bin = 0;
		for (int i = 0; i < N; i++) {
			if (c[N - 1][i])
				bin += (1 << i);
			if (c[i][N - 1])
				bin += (1 << (i + 10));
		}
		edge[bin]++;

//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++)
//				cout << c[i][j];
//			cout << endl;
//		}
//		cout << endl;
	}
	int ans = 0;
	for (auto i = edge.begin(); i != edge.end(); i++)
		ans += i->second * (i->second - 1) / 2;
	cout << ans;
}
