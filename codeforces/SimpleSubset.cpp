#include <bits/stdc++.h>
using namespace std;

int n, v[1000];
vector<int> one, two, three;
bool sieve[2000001];

int main() 
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    for (int i = 2; i <= 2000000; i++)
        if (!sieve[i])
            for (int j = 2 * i; j <= 2000000; j += i)
                sieve[j] = true;

    for (int i = 0; i < n && !one.size(); i++)
        for (int j = 0; j < i && !one.size(); j++)
            if (!sieve[v[i] + v[j]])
            {
                one.push_back(v[i]);
                one.push_back(v[j]);
            }

    for (int i = 0; i < n; i++)
        if (v[i] == 1)
            two.push_back(1);
    
    for (int i = 0; i < n; i++)
        if (!sieve[v[i] + 1] && two.size() >= 1 && v[i] != 1)
        {
            two.push_back(v[i]);
            break;
        }

    if (one.size() == 0 && two.size() == 0)
        printf("1\n%d", v[0]);
    else
    {
        printf("%d\n", max(one.size(), two.size()));
        for (int i = 0; i < max(one.size(), two.size()); i++)
            printf("%d ", (one.size() > two.size() ? one[i] : two[i]));
    }   

    return 0;
}
