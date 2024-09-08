#include <iostream>
#define MAXN (int) 2e5 + 10

using namespace std;

int n, s, arr[MAXN], soma[MAXN], resp;

int32_t main()
{
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	soma[0] = 1, resp = 1e9;
	int l = 1;
	for (int r = 1; r <= n; r++)
	{
		for (int i = 2*s; i >= arr[r]; i--) soma[i] += soma[i-arr[r]];

		cout << l << ' ' << soma[s] << ' ' << soma[s - arr[l]] << endl;
		while (soma[s] - soma[s - arr[l]] > 0)
		{
			for (int i = 2*s; i >= arr[l]; i--) soma[i] -= soma[i-arr[l]];
			l++;
		}


		if (soma[s]) resp = min(resp, r-l+1);
	}

	cout << resp << endl;
}
