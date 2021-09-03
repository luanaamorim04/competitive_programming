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
#include <stack>
#include <bitset>
#include <deque>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e3 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, psa[MAX][MAX];
char tab[MAX][MAX];

int f(int x)
{
	deque<par> menor[MAX];
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= m; j++)
		{
			while (!menor[j].empty() && menor[j].back().first > psa[i][j]) menor[j].pop_back();
			menor[j].push_back({psa[i][j], i});
		}

	for (int i = x+1; i <= n+1; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (menor[j].front().first >= x) return 1;
			while (!menor[j].empty() && menor[j].front().second <= i-x) menor[j].pop_front();
		}

		for (int j = 1; j <= m && i <= n; j++)
		{
			while (!menor[j].empty() && menor[j].back().first > psa[i][j]) menor[j].pop_back();
			menor[j].push_back({psa[i][j], i});
		}
	}

	return 0;
}

int main()
{_	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> tab[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
		{
			if (tab[i][j] == tab[i][j+1]) psa[i][j] = psa[i][j+1] + 1;
			else psa[i][j] = 1;	
		}

	int ini = 1, meio, fim = min(n, m);
	while (ini <= fim)
	{
		meio = ini + ((fim-ini)>>1);
		if (f(meio)) ini = meio + 1;
		else fim = meio - 1;
	}

	cout << (ini - 1)*(ini - 1) << endl;
}










