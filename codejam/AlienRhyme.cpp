#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode(char cc = '$', TrieNode* p = nullptr) : c(cc), par(p) {
        for (int i = 0; i < 26; ++i) child[i] = nullptr;
    }
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) free(child[i]);
    }

    void insert(string& s, int i) {
        ++sz;
        if (s.length() == i) return;
        if (child[s[i] - 'A'] == nullptr)
            child[s[i] - 'A'] = new TrieNode(s[i], this);
        child[s[i] - 'A']->insert(s, i + 1);
    }

    void print(string s) {
        cout << (s + c) << ": " << sz << endl;
        for (int i = 0; i < 26; ++i) {
            if (child[i] == nullptr) continue;
            child[i]->print(s + c);
        }
    }

    int greed() {
        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            if (child[i] == nullptr) continue;
            ret += child[i]->greed();
        }

        if (par == nullptr) return ret;

        for (int i = 0; i < 26; ++i) {
            if (child[i] == nullptr) continue;
            if (sz >= 2) {
                ret += 2;
                sz -= 2;

                TrieNode* it = par;
                while (it != nullptr) {
                    it->sz -= 2;
                    it = it->par;
                }

                break;
            }
        }

        return ret;
    }

    TrieNode* par;
    char c;
    int sz = 0;
    TrieNode* child[26];
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;

        TrieNode* root = new TrieNode();
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;

            reverse(s.begin(), s.end());
            root->insert(s, 0);
        }

        cout << "Case #" << t << ": " << root->greed() << endl;

        free(root);
    }
}
