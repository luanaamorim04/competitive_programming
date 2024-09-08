#include <iostream>
#define int long long
#define MAXN (int) (2e5 + 10)

using namespace std;

int resp, n, m, a[MAXN], b[MAXN];

int32_t main()
{
	cin >> n >> m;
	a[0] = b[0] = a[n+1] = b[m+1] = 1e9 + 10;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 1; j <= m; j++) cin >> b[j];

	int ra = 1, rb = 1, la = 1, lb = 1;
	while (ra <= n && rb <= m)
	{
		while (a[la] != a[ra]) la++;
		while (b[lb] != b[rb]) lb++;
		while (a[ra] == a[ra+1]) ra++;
		while (b[rb] == b[rb+1]) rb++;

		if (a[ra] == b[rb]) resp += ((ra-la+1)*(rb-lb+1));
		if (ra <= n && a[la] <= b[lb]) ra++;
		if (rb <= m && b[lb] <= a[la]) rb++;
	}

	cout << resp << endl;
}	
