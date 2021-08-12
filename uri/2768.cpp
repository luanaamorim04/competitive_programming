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
#define INF 0x3f3f3f3f
#define MAX (int) (1e2 + 5)
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

int n, m, a, b, c, q;
ll dist[MAX][MAX][MAX];

int main()
{_
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
					dist[i][j][0]=(i==j?0:INF);

		while (m--)
		{
			cin >> a >> b >> c;
			dist[a][b][0] = dist[b][a][0] = c;
		}

		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dist[i][j][k] = dist[i][j][k-1];

			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dist[i][j][k] = min(min(dist[i][j][k-1], dist[i][j][k]), dist[i][k][k] + dist[k][j][k]);
		}

		cin >> q;
		while (q--)
		{
			cin >> a >> b >> c;
			cout << (dist[a][b][c]==INF?-1:dist[a][b][c]) << endl;
		}
	}
}













