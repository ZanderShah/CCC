#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        string s;
        cin >> N >> s;
        string ss = "";
        for (char c : s) ss += c == 'E' ? 'S' : 'E';
        cout << "Case #" << t << ": " << ss << endl;
    }
}
