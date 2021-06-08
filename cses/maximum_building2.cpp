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
#include <stdio.h>
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

int n, m, tab[1<<10][1<<10], psa[1<<10], qnt[1<<10][1<<10];
char c;
stack<par> pilha; // {height, width}

void update(int i, int j)
{
	int last = j;
	while (!pilha.empty() && pilha.top().first > i)
	{
		last = pilha.top().second;
		int Hu = pilha.top().first;
		pilha.pop();
		int Hl = (!pilha.empty() ? max(pilha.top().first, i) : i);
		int W = j - last;

		qnt[Hl + 1][W]++;
		qnt[Hu + 1][W]--;
	}

	pilha.push({i, last});
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> c;
			tab[i][j] = (c == '*' ? 0 : tab[i-1][j] + 1);
		}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			update(tab[i][j], j);

		update(0, m+1);
		pilha.pop();
	}

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			qnt[i][j] += qnt[i][j+1];

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			qnt[i][j] += qnt[i][j+1];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			qnt[i][j] += qnt[i-1][j];


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << qnt[i][j] << ' ';
		}
		cout << endl;
	}


		
}


/**/








