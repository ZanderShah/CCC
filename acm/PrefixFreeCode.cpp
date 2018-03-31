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

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

ll f[MAXN];
int n, k, res[MAXN], bit[MAXN];
unordered_map<string, int> dict;
string ss;
vector<string> s;

void update(int x)
{
    for (; x < MAXN; x += x & -x)
        bit[x]++;
}

ll query(int x)
{
    ll ret = 0;
    for (; x > 0; x -= x & -x)
        ret += bit[x];
    return ret;
}

struct Node
{
    Node() : n(0)
    {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
    int n;
    Node *children[26];
};

struct Trie
{
    Trie()
    {
        start = new Node();
    }

    Node *start;

    void add(Node *cur, string &s, int i);
    pii longest(Node *cur, string &s, int i, int l);
    void label(Node *cur, int &n);
};

void Trie::add(Node* cur, string &s, int i)
{
    if (s.length() == i)
        return;

    int j = s[i] - 'a';
    if (cur->children[j] == nullptr)
        cur->children[j] = new Node();

    add(cur->children[j], s, i + 1);
}

pii Trie::longest(Node *cur, string &s, int i, int l)
{
    if (s.length() == i)
        return pii(cur->n, l);

    int j = s[i] - 'a';

    if (cur->children[j] == nullptr)
        return pii(cur->n, l);

    return longest(cur->children[j], s, i + 1, l + 1);
}

void Trie::label(Node *cur, int &n)
{
    bool leaf = true;
    for (int i = 0; i < 26; ++i)
    {
        if (cur->children[i] != nullptr)
        {
            label(cur->children[i], n);
            leaf = false;
        }
    }

    if (leaf)
        cur->n = n++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    Trie t;
    for (int i = 0; i < n; ++i)
    {
        cin >> ss;
        t.add(t.start, ss, 0);
    }
    int l = 0;
    t.label(t.start, l);

    f[n - k] = 1;
    f[n - k + 1] = n - k + 1;
    for (ll i = n - k + 2; i <= n; ++i)
        f[i] = i * f[i - 1] % MOD;

    cin >> ss;

    int pos = 0;
    vector<int> id;
    while (pos < ss.length())
    {
        pii x = t.longest(t.start, ss, pos, 0);
        id.push_back(x.first);
        pos += x.second;
    }

    ll ret = 0;
    for (int i = 0; i < id.size(); ++i)
    {
        ret = (ret + f[n - i - 1] * (id[i] - query(id[i] + 1))) % MOD;
        update(id[i] + 1);
    }

    cout << (ret + 1) % MOD << endl;
}
