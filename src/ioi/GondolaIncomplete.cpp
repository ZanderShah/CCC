#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1e9 + 9;
set<int> s;
vector<pii> v;

int valid(int n, int inputSeq[]) {
	s.clear();

	// Grab one element to make the checking easier
	// Check for duplicate entries as well
	int mark = -1;
	for (int i = 0; i < n; i++) {
		if (inputSeq[i] <= n)
			mark = i;
		if (s.find(inputSeq[i]) != s.end())
			return 0;
		s.insert(inputSeq[i]);
	}

	// If no element is less than n then the sequence is always valid
	if (mark == -1)
		return 1;

	// Move back to the front of the gondola
	mark = (mark - inputSeq[mark] + 1 + n) % n;

	// Check for an increasing sequence
	int val = inputSeq[mark];
	for (int i = 1; i < n; i++)
		if (inputSeq[(mark + i) % n] <= n) {
			if (inputSeq[(mark + i) % n] < val)
				return 0;
			val = inputSeq[(mark + i) % n];
		}
	return 1;
}

int replacement(int n, int gondolaSeq[], int replacementSeq[]) {
	v.clear();

	// Grab one element to make the checking easier
	int mark = -1;
	for (int i = 0; i < n; i++)
		if (gondolaSeq[i] <= n)
			mark = i;

	// If no element is less than n, treat it as if the first spot used to be 1
	if (mark == -1) {
		for (int i = 0; i < n; i++)
			v.pb(mp(gondolaSeq[i], i + 1));
	} else {
		// Move back to the front of the gondola
		mark = (mark - gondolaSeq[mark] + 1 + n) % n;
		for (int i = 0; i < n; i++)
			v.pb(mp(gondolaSeq[(mark + i) % n], i + 1));
	}

	sort(v.begin(), v.end());

	// Simulate the replacement sequence
	mark = n;
	for (int i = 0, j = 0; i < v.size(); i++)
		while (mark < v[i].first) {
			replacementSeq[j] = v[i].second;
			mark++;
			v[i].second = mark;
			j++;
		}

	return v[v.size() - 1].first - n;
}

int countReplacement(int n, int inputSeq[]) {
	if (!valid(n, inputSeq))
		return 0;
	return 1;
}
