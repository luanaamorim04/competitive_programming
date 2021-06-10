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
#include <stack>
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

ll qnt[2005][2005], tab[2005][2005], n, m, a, b, resp, cor[2005][2005];
stack<par> pilha;

void update(int i, int j)
{
	int last = j;
	while (!pilha.empty() && pilha.top().first > i)
	{
		last = pilha.top().second;
		int Hu = pilha.top().first;
		ll W = j - last;
		pilha.pop(); 
		int Hl = (!pilha.empty() ? max(pilha.top().first, i) : i);
		qnt[Hl + 1][W]++;
		qnt[Hu + 1][W]--;
	}
	pilha.push({i, last});
}

ll solve(int x)
{
	resp = 0;
	int i, j;
	memset(qnt, 0, sizeof qnt);
	memset(tab, 0, sizeof tab);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			if (x) tab[i][j] = (cor[i][j] == -1 ? 0 : tab[i-1][j] + 1);
			else tab[i][j] = (cor[i][j] != -1 ? 0 : tab[i-1][j] + 1);
		}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			update(tab[i][j], j);

		update(0, n+1);
		pilha.pop();
	}

	for (i = 1; i <= n; i++)
	{
		for (j = n; j >= 1; j--) qnt[i][j] = (qnt[i][j] + qnt[i][j+1]) % MOD;
		for (j = n; j >= 1; j--) qnt[i][j] = (qnt[i][j] + qnt[i][j+1]) % MOD;
	}

	for (i = 1; i <= n; i++) 
		for (j = 1; j <= n; j++)
			qnt[i][j] = (qnt[i][j] + qnt[i-1][j] + (2*MOD)) % MOD;

	for (i = 1; i <= n; i++) 
		for (j = 1; j <= n; j++)
			resp = (resp + (i*j*qnt[i][j])) % MOD;

	return resp;
}

int main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		cor[a][b] = -1;
	}

	cout << (solve(0) + solve(1)) % MOD << endl;
}	




















