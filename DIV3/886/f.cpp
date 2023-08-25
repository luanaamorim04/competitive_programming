#include <iostream>
#include <vector>
#include <queue>
#define int unsigned long long
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9)

using namespace std;

int t, n, arr[MAXN], freq[MAXN], pos[MAXN], resp;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		resp = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			if (arr[i] > n) continue;
			freq[arr[i]]++;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j+=i)
				pos[j] += freq[i];
		}

		for (int i = 1; i <= n; i++)
		{
			resp = max(resp, pos[i]);
			freq[i] = 0;
			pos[i] = 0;
		}
		cout << resp << endl;
	}
}