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

int dist[MAX][MAX], n, m, k, q, a, b, t;
queue<par> fila;
par resp[MAX][MAX];

int main()
{_
	while (cin >> n >> m && n)
	{
		if (t) cout << endl;
		memset(dist, 0, sizeof dist);
		cin >> k;
		while (k--)
		{
			cin >> a >> b;
			dist[a][b] = 1;
			resp[a][b] = {a, b};
			fila.push({a, b});
		}

		for (int i = 0; i <= max(n, m)+1; i++)
			dist[i][0] = dist[0][i] = dist[n+1][i] = dist[i][m+1] = INF;

		while (!fila.empty())
		{
			auto[a, b] = fila.front(); fila.pop();
			for (int i = -1; i <= 1; i++)
				for (int j = -1; j <= 1; j++)
				{
					if (!i || !j)
					{
						if (!dist[a+i][b+j])
						{
							dist[a+i][b+j] = dist[a][b] + 1;
							resp[a+i][b+j] = resp[a][b];
							fila.push({a+i, b+j});
						}
						else if (dist[a+i][b+j] == dist[a][b]+1)
						{
							resp[a+i][b+j] = min(resp[a][b], resp[a+i][b+j]);
						}
					}
				}
		}

		cout << "Instancia " << ++t << endl;
		cin >> q;
		while (q--)
		{
			cin >> a >> b;
			cout << resp[a][b].first << ' ' << resp[a][b].second << endl;
		}
	}

}











