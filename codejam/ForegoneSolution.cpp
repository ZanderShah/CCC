#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string N;
        long long A = 0, B = 0;
        cin >> N;
        for (char c : N) {
            A *= 10;
            B *= 10;
            if (c == '5') {
                A += 3;
                B += 2;
            } else if (c != '0') {
                A += c - '0' - 1;
                B += 1;
            }
        }

        if (A == 0) {
            ++A;
            --B;
        }

        printf("Case #%d: %lld %lld\n", t, A, B);
    }
}
