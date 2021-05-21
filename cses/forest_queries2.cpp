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
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int ft[1<<10][1<<10], a, b, c, d, tab[1<<10][1<<10], n, m, op;
char C;

void update(int a, int b, int val)
{
	for (int i = a; i <= n; i += lsb(i))
		for (int j = b; j <= n; j += lsb(j))
			ft[i][j] += val;
}

int query(int a, int b)
{
	int ans = 0;
	for (int i = a; i > 0; i -= lsb(i))
		for (int j = b; j > 0; j -= lsb(j))
			ans += ft[i][j];
	return ans;
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> C;
			tab[i][j] = (C == '*');
			update(i, j, tab[i][j]);
		}

	while (m--)
	{
		cin >> op;
		if (op == 2)
		{
			cin >> a >> b >> c >> d;
			cout << query(c, d) + query(a-1, b-1) - query(a-1, d) - query(c, b-1) << endl; 
		}
		else
		{
			cin >> a >> b;
			tab[a][b] ^= 1;
			int val = tab[a][b] ? 1 : -1;
			update(a, b, val);
		}
	}
}









