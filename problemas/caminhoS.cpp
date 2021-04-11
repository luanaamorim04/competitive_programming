#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<ll, ll>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, tab[303][303], nivel[303][303], maxn;
queue<par> fila;

int pode(ll k, int a, int b)
{
	return (a >= 0 && b >= 0 && a < n && b < n && !nivel[a][b] && tab[a][b] <= k);
}

par f(ll x)
{
	memset(nivel, 0, sizeof(nivel));
	fila.push({0, 0}); 
	nivel[0][0] = 1, maxn = 0;
	if (tab[0][0] > x) return {0, 0};
	while (!fila.empty())
	{
		int a = fila.front().first, b = fila.front().second; fila.pop();
		maxn = max(maxn, tab[a][b]);
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
			{
				if (!pode(x, a + i, b + j) || (i && j)) continue;
				nivel[a + i][b + j] = nivel[a][b] + 1;
				fila.push({a + i, b + j});
			}
	}

	return {nivel[n - 1][n - 1], maxn};
}

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> tab[i][j];
	
	ll ini = 1, meio, fim = 1e9;
	while (ini <= fim)
	{
		meio = ini + (fim-ini)/2;
		if (f(meio).first) fim = meio - 1;
		else ini = meio + 1;
	}

	par resp = f(fim + 1);

	cout << resp.second << ' ' << resp.first << endl;
}
