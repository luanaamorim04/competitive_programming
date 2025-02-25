#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e3 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int maior[MAXN][MAXN], menor[MAXN][MAXN], a, b, resp, n, t, arr[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) 
		{
			cin >> arr[i];
			menor[i][i] = 0;
			maior[i][i] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = i+1; j <= n; j++)
			{
				menor[i][j] = menor[i][j-1] + (arr[j] < arr[i]);
				maior[i][j] = maior[i][j-1] + (arr[j] > arr[i]);
			}
		}

		int resp = 1e9;
		for (int l = 1; l <= n; l++)
		{
			for (int r = l; r <= n; r++)
			{
				//inv que al tem 
				if (resp > maior[l][r] - menor[l][r]) a = l, b = r, resp = maior[l][r] - menor[l][r];

			}
		}
		cout << a << ' ' << b << endl;
	}
}
