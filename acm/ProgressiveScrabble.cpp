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

int n, u[85];
string s;

string e() {
    for (int i = 2; i < s.length(); i++) {
        u[i] = s[i] == ' ' ? 0 : s[i] - 'a' + 1;
    }
    for (int i = 3; i < s.length(); i++) {
        u[i] += u[i - 1];
    }
    string ret = "";
    for (int i = 2; i < s.length(); i++) {
        ret += u[i] % 27 == 0 ? ' ' : (char)(u[i] % 27 - 1 + 'a');
    }
    return ret;
}

string d() {
    for (int i = 2; i < s.length(); i++) {
        u[i] = s[i] == ' ' ? 0 : s[i] - 'a' + 1;
    }
    for (int i = s.length() - 1; i >= 3; i--) {
        u[i] = (u[i] - u[i - 1] + 27) % 27;
    }
    string ret = "";
    for (int i = 2; i < s.length(); i++) {
        ret += u[i] % 27 == 0 ? ' ' : (char)(u[i] % 27 - 1 + 'a');
    }
    return ret;
}

int main() {
    cin >> n;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        cout << (s[0] == 'e' ? e() : d()) << endl; 
    }
}
