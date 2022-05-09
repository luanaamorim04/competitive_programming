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

int t, n, idx;
char tab[1<<10][1<<10];
par a[4];

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n;
		idx = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> tab[i][j];
				if (tab[i][j] == '*')
				{	
					a[idx++] = {i, j};
				}
			}
		}

		if (a[0].second == a[1].second) 
		{
			if (a[0].second)
			{
				tab[a[0].first][a[1].second - 1] = '*';
				tab[a[1].first][a[0].second - 1] = '*';
			}
			else
			{
				tab[a[0].first][a[1].second + 1] = '*';
				tab[a[1].first][a[0].second + 1] = '*';
			}
		}
		else if (a[0].first == a[1].first) 
		{
			if (a[0].first)
			{
				tab[a[0].first - 1][a[1].second] = '*';
				tab[a[1].first - 1][a[0].second] = '*';
			}
			else
			{
				tab[a[0].first + 1][a[1].second] = '*';
				tab[a[1].first + 1][a[0].second] = '*';
			}
		}
		else
		{
			tab[a[0].first][a[1].second] = '*';
			tab[a[1].first][a[0].second] = '*';
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << tab[i][j];
			}
			cout << endl;
		}
	}
}

