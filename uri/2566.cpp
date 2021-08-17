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

ll dist[101][101][2], n, m, a, b, c, t;

int main()
{_
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j][0] = dist[i][j][1] = (i==j?0:INF);
		while (m--)
		{
			cin >> a >> b >> t >> c;
			dist[a][b][t] = c;
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
				{
					dist[i][j][0] = min(dist[i][j][0], dist[i][k][0] + dist[k][j][0]);
					dist[i][j][1] = min(dist[i][j][1], dist[i][k][1] + dist[k][j][1]);
				}

		cout << min(dist[1][n][0], dist[1][n][1]) << endl;
	}
}



