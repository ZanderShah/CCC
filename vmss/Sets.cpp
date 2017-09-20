#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> adj[26];
bool vis[26], mentioned[26], letters[26][26];
char x, y;
string trash;

void dfs(int x, int p)
{
	vis[x] = true;
	for (int i = 0; i < adj[x].size(); i++)
		if (!vis[adj[x][i]])
			dfs(adj[x][i], p);
	for (int i = 0; i < 26; i++)
		if (letters[x][i])
			letters[p][i] = true;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> trash >> y;
		mentioned[x - 'A'] = true;

		if (y <= 'Z')
		{
			adj[x - 'A'].push_back(y - 'A');
			mentioned[y - 'A'] = true;
		}
		else
			letters[x - 'A'][y - 'a'] = true;
	}

	for (int i = 0; i < 26; i++)
		if (mentioned[i])
		{
			memset(vis, false, sizeof vis);
			dfs(i, i);

			printf("%c = {", (char) (i + 'A'));
			bool first = true;
			for (int j = 0; j < 26; j++)
				if (letters[i][j])
				{
					if (!first)
						printf(",");
					else
						first = false;
					printf("%c", (char) (j + 'a'));
				}
			printf("}\n");
		}
}
