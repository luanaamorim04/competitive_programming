//#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, a, b;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		if (b > a)
		{
			cout << (b==a+1 ? "YES" : "NO") << endl;
		}
		else
		{
			cout << ((a-b+1)%9 == 0 ? "YES" : "NO") << endl;
		}
	}
}
