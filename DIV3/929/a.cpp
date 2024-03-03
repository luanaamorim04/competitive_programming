#include <iostream>
#include <vector>
#define MAXN (int) (2e5 + 10)
#define INF 1e9
#define all(x) x.begin(), x.end()
#define int long long
#define ii pair<int, int>

using namespace std;

int n, m, t, k;

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> n;
		int soma = 0;
        for (int i = 1; i <= n; i++)
		{
			cin >> k;
			soma += abs(k);
		}
		cout << soma << endl;

	}
}
