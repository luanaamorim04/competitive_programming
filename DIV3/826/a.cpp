//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAXN (int) (2e5 + 10)
#define int long long
#define INF 1e9
#define all(x) x.begin(), x.end()
#define dbug(x) cout << #x << ": " << x << endl;

using namespace std;

int n, arr[MAXN], t, m, k;
string a, b;

int tam(char c)
{
	if (c == 'X') return 0;
	if (c == 'S') return 1;
	if (c == 'M') return 2;
	if (c == 'L') return 3;
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		int s1 = 0, s2 = 0;
		for (char c : a)
			s1 = max(s1, tam(c));
		for (char c : b)
			s2 = max(s2, tam(c));

		if (s1 < s2) cout << '<' << endl;
		else if (s1 > s2) cout << '>' << endl;
		else
		{
			if (s1 == 1) swap(a, b);
			if (a.size() < b.size()) cout << '<' << endl;
			else if (a.size() > b.size()) cout << '>' << endl;
			else cout << "=" << endl;
		}

	}
	return 0;
}






