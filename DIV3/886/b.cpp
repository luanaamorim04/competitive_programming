#include <iostream>
#include <vector>
#include <queue>
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9)

using namespace std;

int t, n, a[MAXN], b[MAXN], c[MAXN];

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		int resp, maior = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i];
			if (a[i] > 10) continue;
			if (maior < b[i])
			{
				maior = b[i];
				resp = i;
			}
		}

		cout << resp << endl;
	}
}