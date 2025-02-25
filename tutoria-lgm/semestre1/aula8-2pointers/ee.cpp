#include <iostream>
#define MAXN (int) (3e5 + 10)
#define int long long

using namespace std;

int n, s, arr[MAXN], resp, soma, val[MAXN], tmp;

int32_t main()
{
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) cin >> val[i];

	int l = 1;
	for (int r = 1; r <= n; r++)
	{
		soma += arr[r];
		tmp += val[r];
		while (soma > s) soma -= arr[l], tmp -= val[l], l++;

		resp = max(resp, tmp);
	}

	cout << resp << endl;
}


