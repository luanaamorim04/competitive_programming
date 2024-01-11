#include <iostream>
#define int long long
#define MAXN (int) (2e5 + 10)
#define INF 1e9
#define all(x) x.begin(), x.end()

using namespace std;

int solve(int k)
{
	int esq, dir;
	if (l[0] > k) return 0;
	esq = l[0], dir = min(k, r[0]);
	for (int i = 1; i < n; i++)
	{
		if (l[i] > l[i-1]) esq = min(l[i], dir+k);
		else esq = max(l[i], esq-k);

		if (r[i] > r[i-1]) dir = min(r[i], dir+k);
		else dir = max(r[i], esq-k);

		if (esq != l[i] || dir != r[i]) return 0;
	}
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> l[i] >> r[i];
		}

		int ini = 0, meio, fim = n;
		while (ini <= fim)
		{
			meio = (ini+fim)>>1;
			if (solve(meio)) fim = meio - 1;
			else ini = meio + 1;
		}
		cout << fim + 1 << endl;
	}
}
