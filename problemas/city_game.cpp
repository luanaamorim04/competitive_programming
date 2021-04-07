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
#define ll long long
#define INF (1e9)
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, tab[1<<10][1<<10], esq[1<<10], dir[1<<10], resp, t;
char c;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		resp = 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				cin >> c;
				tab[i][j] = 0;
				c == 'F' ? tab[i][j] = 1 + tab[i - 1][j] : tab[i][j] = 0;
			}

		for (int i = 1; i <= n; i++)
		{
			tab[i][0] = tab[i][m + 1] = -1;
			for (int j = 1; j <= m; j++)
			{
				esq[j] = j - 1;
				while (tab[i][esq[j]] >= tab[i][j]) esq[j] = esq[esq[j]];
			}

			for (int j = m; j >= 1; j--)
			{
				dir[j] = j + 1;
				while (tab[i][dir[j]] >= tab[i][j]) dir[j] = dir[dir[j]];
				resp = max(resp, tab[i][j]*(dir[j]-esq[j]-1));
			}
		}

		cout << resp*3 << endl;
	}
}
