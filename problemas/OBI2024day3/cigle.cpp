#include <iostream>
#define MAXN (int) (5e3 + 10)

using namspace std;

int dp[MAXN][MAXN], n, arr[MAXN], custo[MAXN][MAXN];

int query(int idx, int i, int j, int l, int r)
{

}

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = i-1; j >= 1; j--)
		{
			dp[i] = query(1, 0, n, 0, j);
			update(1, 0, n, i-j, dp[i] + );
		}
	}

	cout << dp[n] << endl;
}
