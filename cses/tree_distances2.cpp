#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> grafo[1<<20];
queue<par> fila;
ll sum[1<<20], qnt[1<<20], pai[1<<20], n, a, b, resp[1<<20];

int f(int u, int p)
{
	qnt[u] = 1, pai[u] = p;
	for (int v : grafo[u])
	{
		if (v == p) continue;
		qnt[u] += f(v, u);
		sum[u] += qnt[v] + sum[v];
	}

	return qnt[u];
}

int main()
{_
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	f(1, 0);

	fila.push({1, 0});
	resp[0] = sum[1] + qnt[1];
	while (!fila.empty())
	{
		int u = fila.front().first, p = fila.front().second; fila.pop();
		resp[u] = resp[p] + n - (qnt[u]<<1);

		for (int v : grafo[u])
		{
			if (v == p) continue;
			fila.push({v, u});
		}
	}

	for (int i = 1; i <= n; i++)
	{ 
		cout << resp[i] << ' ';
	}
	cout << endl;
}





