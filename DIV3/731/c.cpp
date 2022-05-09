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
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
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

int t, a[101], b[101], k, n, m;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> k >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		int ok = 1;
		int x = 0, y = 0, z = k;
		while (x < n || y < m)
		{
			if (y != m && b[y] <= z) 
			{
				z += !b[y];
				y++;
				continue;
			}
			if (x != n && a[x] <= z)
			{
				z += !a[x];
				x++;
				continue;
			}
			ok = 0;
			break;
		}

		if (!ok) 
		{
			cout << -1 << endl;
			continue;
		}

		x = 0, y = 0;
		while (x < n || y < m)
		{
			if (y != m && b[y] <= k)
			{
				cout << b[y] << ' ';
				k += !b[y];
				y++;
			}
			else if (x != n || a[x] <= k)
			{
				cout << a[x] << ' ';
				k += !a[x];
				x++;
			}
		}
		cout << endl;
	}
}






