#include <bits/stdc++.h>
#include <vector>
#include <queue>
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9)

using namespace std;

int t, n, k, arr[MAXN];
char c;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		int last = 0, maior = 0;
		cin >> n >> k;
		int ok = 0, resp = INF;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr, arr+n);

		// 8 3 1 4 5 10 7 3
		// k = 1
		// 1 3 3 4 5 7 8 10

		for (int i = 1; i < n; i++) // 1 2 5 6
		{
			if (arr[i] - arr[i-1] > k) 
			{
				maior = max(maior, i-last);
				last = i;
			}
		}

		maior = max(maior, n - last);

		cout << n-maior << endl;
	}
}