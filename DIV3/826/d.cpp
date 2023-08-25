//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAXN (int) (3e5 + 10)
#define MAXL 20
#define int long long
#define INF 1e9
#define all(x) x.begin(), x.end()
#define dbug(x) cout << #x << ": " << x << endl;

using namespace std;

int n, arr[MAXN], t, m, k, ini[MAXN][MAXL];

int check(int l, int r, int nivel)
{
	int menor = INF, maior = 0;
	for (int i = l; i <= r; i++)
		menor = min(menor, arr[i]), maior = max(maior, arr[i]);

	if (maior-menor >= nivel) return 0;
	return 1;
}

int sorta(int l, int r, int nivel)
{
	if (ini[arr[l]][nivel]) return 0;
	int idx = n;
	for (int i = l; i <= r; i++)
		idx = min(idx, arr[i]);

	for (int i = l; i <= r; i++)
		arr[i] = idx++;

	return 1;
}

int solve(int n)
{
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			ini[j][i] = 0;

	for (int i = 1; i < 20; i++)
	{
		int m = 1<<i;
		for (int j = 1; j+m-1 <= n; j+=m)
			ini[j][i] = 1;
	}

	for (int i = 1; i < 20; i++)
	{
		int m = 1<<i;
		for (int idx = 1; idx+m-1 <= n; idx+=m)
			if (!check(idx, idx+m-1, m)) return -1;
	}

	int resp = 0;
	for (int i = 1; i < 20; i++)
	{
		int m = 1<<i;
		for (int idx = 1; idx+m-1 <= n; idx+=m)
		{
			resp += sorta(idx, idx+m-1, i);
		}
	}

	return resp;
}


int32_t main()
{
	cin >> t;
	while (t--)
	{
		int soma = 0, resp = INF;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		cout << solve(n) << endl;
		
	}
	return 0;
}






