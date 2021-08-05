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

ll dist[300][300], n, m, c, k, a, b, o;

int main()
{_
	while (cin >> n >> m >> o >> k && n)
	{	
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = (i != j ? INF : 0);

		while (m--)
		{
			cin >> a >> b >> c;	
			dist[b][a] = dist[a][b] = c;
		}

		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i < o-1 && k != i + 1) continue;
					if (k < o-1 && j != k + 1) continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		cout << dist[k][o-1] << endl;
	}
}







