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

int t, n, a[MAX][5], b[MAX][5], c[MAX][5];

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n;
		b[0][0] = b[0][1] = b[0][2] = b[0][3] = b[0][4] = INF;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
			b[i][0] = min(b[i-1][0], a[i][0]);
			b[i][1] = min(b[i-1][1], a[i][1]);
			b[i][2] = min(b[i-1][2], a[i][2]);
			b[i][3] = min(b[i-1][3], a[i][3]);
			b[i][4] = min(b[i-1][4], a[i][4]);
		}

		c[n+1][0] = c[n+1][1] = c[n+1][2] = c[n+1][3] = c[n+1][4] = INF;
		for (int i = n; i >= 1; i--)
		{
			c[i][0] = min(c[i+1][0], a[i][0]);
			c[i][1] = min(c[i+1][1], a[i][1]);
			c[i][2] = min(c[i+1][2], a[i][2]);
			c[i][3] = min(c[i+1][3], a[i][3]);
			c[i][4] = min(c[i+1][4], a[i][4]);
		}
		for (int i = n; i >= 1; i--)
		{
			int k = 0;
			k += (a[i][0] < min(c[i+1][0], b[i-1][0]));
			k += (a[i][1] < min(c[i+1][1], b[i-1][1]));
			k += (a[i][2] < min(c[i+1][2], b[i-1][2]));
			k += (a[i][3] < min(c[i+1][3], b[i-1][3]));
			k += (a[i][4] < min(c[i+1][4], b[i-1][4]));
			if (k >= 3)
			{
				cout << i << endl;
				break;
			} 

			if (i == 1) cout << -1 << endl;
		}
	}
}













