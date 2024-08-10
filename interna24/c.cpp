#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define MOD (int) (1e9 + 7)
#define INF (int) (1e9 + 10)
#define all(x) x.begin(), x.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)

using namespace std;

int t, a, b;

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		int resp = 0;
		while (a && b && a != b)
		{
			if (b > a) swap(a, b);
			resp += (a/b);
			a %= b;
		}

		cout << (!resp ? 0 : resp - 1)  << endl;
	}
}


