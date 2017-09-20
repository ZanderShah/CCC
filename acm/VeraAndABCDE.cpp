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

string A[5] = {"***", "*.*", "***", "*.*", "*.*"};
string B[5] = {"***", "*.*", "***", "*.*", "***"};
string C[5] = {"***", "*..", "*..", "*..", "***"};
string D[5] = {"***", "*.*", "*.*", "*.*", "***"};
string E[5] = {"***", "*..", "***", "*..", "***"};

int N;
string s;

int main() {
    cin >> N;
    cin >> s;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N; j++) {
            if (s[j] == 'A') {
                cout << A[i];
            }
            if (s[j] == 'B') {
                cout << B[i];
            }
            if (s[j] == 'C') {
                cout << C[i];
            }
            if (s[j] == 'D') {
                cout << D[i];
            }
            if (s[j] == 'E') {
                cout << E[i];
            }
        }
        cout << endl;
    }
}
