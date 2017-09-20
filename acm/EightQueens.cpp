#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 8;

int r[MAXN], c[MAXN], queens;
bool bad;
string s[MAXN];

int main() {
    for (int i = 0; i < 8; i++) {
        cin >> s[i];
        for (int j = 0; j < 8; j++)
            if (s[i][j] == '*') {
            	queens++;
                r[i]++;
                c[j]++;
                if (r[i] > 1 || c[j] > 1)
                    bad = true;
            }
    }

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (s[i][j] == '*') {
                // Check both diagonals
                for (int x = i + 1, y = j + 1; x < 8 && y < 8; x++, y++)
                    if (s[x][y] == '*')
                        bad = true;

                for (int x = i + 1, y = j - 1; x < 8 && y >= 0; x++, y--)
                    if (s[x][y] == '*')
                        bad = true;
            }

    cout << (bad || queens != 8 ? "invalid" : "valid");
}
