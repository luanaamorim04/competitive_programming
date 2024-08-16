#include <iostream>
#define MAXN 550
#define MOD (int) (1e9 + 7)

using namespace std;

int n, m, a, b, resp[MAXN][MAXN];

int32_t main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		resp[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				resp[i][j] = (resp[i][j] + (resp[i][k]*resp[k][j])) % MOD;
			}
		}
	}

	cout << resp[1][n] << endl;
}
