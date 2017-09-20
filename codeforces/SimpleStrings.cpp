#include <bits/stdc++.h>
using namespace std;

char s[200001];

int main() 
{
    scanf("%s", &s);

    for (int i = 1; i < 200000; i++)
        if (s[i])
        {
            if (s[i] == s[i - 1])
                for (char c = 'a'; c <= 'z'; c++)
                    if (c != s[i - 1] && c != s[i + 1])
                    {
                        s[i] = c;
                        break;
                    }
        }

    for (int i = 0; i < 200000; i++)
        if (s[i])
            cout << s[i];
        else
            break;

    return 0;
}
