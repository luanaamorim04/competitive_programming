#include <iostream>
#include <vector>
#include <queue>
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9)

using namespace std;

int t, a, b, c;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		cout << (a+b+c-min(a, min(b, c)) >= 10 ? "YES": "NO") << endl;
	}
}