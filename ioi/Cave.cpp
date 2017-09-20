#include <bits/stdc++.h>
using namespace std;

// Remember to remove the empty methods before submitting
void answer(int S[], int D[]) {

}

int tryCombination(int S[]) {
	return 0;
}

void exploreCave(int N) {
	int flip[5000], maps[5000];

	memset(flip, 0, sizeof flip);
	memset(maps, -1, sizeof maps);

	for (int i = 0; i < N; i++) {
		bool closed = tryCombination(flip) == i;

		int up = N - 1, low = 0;

		while (low < up) {
			for (int j = low; j <= (up + low) / 2; j++)
				if (maps[j] != -1)
					flip[j] = 1;

			int x = tryCombination(flip);

			for (int j = low; j <= (up + low) / 2; j++)
				if (maps[j] != -1)
					flip[j] = 0;

			if ((closed && x == i) || (!closed && x != i))
				low = (up + low) / 2 + 1;
			else
				up = (up + low) / 2;
		}

		if (closed)
			flip[low] = 1;
		maps[low] = i;
	}

	answer(flip, maps);
}
