#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>

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

string s;
bool vis[26], g;

int main() {
	cin >> s;
	for (int i = 0; i < (int) s.length() - 25; i++) {

		for (int j = 0; j < 26; j++)
			vis[j] = 0;

		g = 1;

		for (int j = 0; j < 26; j++)
			if (s[i + j] != '?') {
				if (vis[s[i + j] - 'A'])
					g = 0;
				vis[s[i + j] - 'A'] = 1;
			}

		if (g) {
			for (int j = 0; j < i; j++)
				if (s[j] == '?')
					printf("A");
				else
					printf("%c", s[j]);

			int x = 0;
			while (x < 26 && vis[x])
				x++;

			for (int j = i; j < i + 26; j++)
				if (s[j] == '?') {
					printf("%c", (char) (x + 'A'));
					x++;
					while (x < 26 && vis[x])
						x++;
				} else
					printf("%c", s[j]);

			for (int j = i + 26; j < s.length(); j++)
				if (s[j] == '?')
					printf("A");
				else
					printf("%c", s[j]);

			return 0;
		}
	}
	printf("-1");
}
