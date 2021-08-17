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
#define INF (1e15)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<ll, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, m, dist[105][105], a, b, c;
par resp[105];

int main()
{_
	while (cin >> n >> m && n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = (i==j?0:INF);
			
		while (m--)
		{
			cin >> a >> b >> c;
			dist[a][b] = dist[b][a] = c;
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		for (int i = 1; i <= n; i++)
		{
			resp[i-1].second = i;
			resp[i-1].first = 0;
			for (int j = 1; j <= n; j++) resp[i-1].first += dist[i][j];
		}

		sort(resp, resp+n);
		for (int i = 0; i < n; i++)
		{
			if (resp[i].first != resp[0].first) break;
			cout << resp[i].second << ' ';
		}

		cout << endl;
	}
}









