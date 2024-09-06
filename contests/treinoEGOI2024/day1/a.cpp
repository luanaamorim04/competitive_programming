#include <iostream>
#define MAXN (int) (2e5 + 10)

using namespace std;

int n, a, b, q, arr[MAXN], dp[MAXN];



int32_t main()
{
	cin >> n >> a >> b >> q;
	for (int i = 1; i <= q; i++) cin >> arr[i];

	for (int i = 1; i <= q; i++)
	{
		dp[i] = dp[i-1] + abs(arr[i]-arr[i-1])
		for (int j = 1; j < i; j++)
			dp[i] = min(dp[i], dp[j]abs(arr[i]-arr[]))
	}
	return 0;
}
