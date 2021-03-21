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
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int tab[1<<10][1<<10], t, n, k;
double a, b, ans;

int flood(int a, int b)
{
	if (tab[a][b] == -1) return k = 1;
	if (tab[a][b] == 1) return 0;
	ans++;
	tab[a][b] = 1;
	flood(a + 1, b);
	flood(a - 1, b);
	flood(a, b + 1);
	flood(a, b - 1);
	return 0;
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n;
		a = b = 0;
		memset(tab, -1, sizeof(tab));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				cin >> tab[i][j];
				a += tab[i][j];
			}		

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				ans = k = 0;
				if (!tab[i][j]) 
				{
					flood(i, j);
					if (!k) b += ans;
				}
			}

		cout << fixed << setprecision(2) << (a+b)/2 << endl;
	}
}
