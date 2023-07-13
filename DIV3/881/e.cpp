#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long

using namespace std;

int t, n, m, q, arr[MAXN], l, r, pos, psa[MAXN], p[MAXN];
vector<pair<int, int> > v;

int pode(int k)
{
	for (int i = 0; i < k; i++)
		arr[p[i]] = 1;

	for (int i = 1; i <= n; i++)
		psa[i] = psa[i-1] + arr[i];

	for (int i = 0; i < k; i++)
		arr[p[i]] = 0;

	for (auto[a, b] : v)
	{
		if ((psa[b] - psa[a-1]) > ((b-a+1)/2)) return 1;
	}

	return 0;
}	

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		v.clear();
		while (m--)
		{
			cin >> l >> r;
			v.push_back({l, r});
		}

		cin >> q;
		for (int i = 0; i < q; i++)
			cin >> p[i];
		
		int ini = 0, meio, fim = q;
		while (ini <= fim)
		{
			meio = (ini+fim)/2;
			// cout << "meio : " << meio << endl;
			if (pode(meio) == 0) ini = meio + 1;
			else fim = meio - 1;
		}

		// cout << pode(3) << endl;
		cout << (fim == q ? -1 : fim+1) << endl;
	}
}