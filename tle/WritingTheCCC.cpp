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
#include <unordered_set>
#include <map>
#include <bitset>
#include <cstdio>
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
typedef unordered_map<int, int> umii;

int T, N;
string s;
map<string, int> ms;
vector<int> ord[100005];

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> s;
		ms[s] = i;
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s;
		ord[ms[s]].pb(i + 1);
	}

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < ord[i].size(); j++) {
			cout << ord[i][j] << endl;
		}
	}
}
