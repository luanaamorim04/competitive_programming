#include <iostream>
#define int long long
#define MAXN (int) (2e5 + 10)
#define INF 1e9
#define all(x) x.begin(), x.end()

using namespace std;

int t, i;
char j;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> j >> i;
		for (char c = 'a'; c <= 'h'; c++)
			if (c != j) cout << c << i << endl;
		for (int k = 1; k <= 8; k++)
			if (k != i) cout << j << k << endl;

	}
}
