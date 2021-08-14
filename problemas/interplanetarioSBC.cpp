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
#define INF (1e9 + 2)
#define MAX (405)
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

int i, j, k, n, m, a, b, c, q, t, pos[MAX][2], idx, idx1, mp[MAX][2], dist[MAX][MAX][2];
par arr[MAX];

struct Qr
{
	int a, b, idx, t;
};

vector<Qr> query[MAX];
vector<par> resp;

int main()
{_
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		arr[i].second = i;
		cin >> arr[i].first;
		for (j = 1; j <= n; j++)
			dist[i][j][0] = dist[i][j][1] = (i==j?0:INF);
	}
	
	sort(arr+1, arr+1+n);
	arr[0].first = arr[n+1].first = INF;
	for (i = 1; i <= n; i++)
	{
		pos[arr[i].second][0] = i;
		pos[arr[i].second][1] = n-i+1;
		idx += (arr[i].first != arr[i-1].first);
		idx1 += (arr[n-i+1].first != arr[n-i+2].first);
		mp[idx1][1] = mp[idx][0] = i; 
	}

	while (m--)
	{
		cin >> a >> b >> c;
		dist[pos[a][0]][pos[b][0]][0] = dist[pos[b][0]][pos[a][0]][0] = c;
		dist[pos[a][1]][pos[b][1]][1] = dist[pos[b][1]][pos[a][1]][1] = c;
	}

	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		cin >> a >> b >> c >> t;
		c = min(c, t?idx1:idx);
		query[mp[c][t]].push_back({pos[a][t], pos[b][t], i, t});
	}

	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				dist[i][j][0] = min(dist[i][j][0], dist[i][k][0] + dist[k][j][0]);
				dist[i][j][1] = min(dist[i][j][1], dist[i][k][1] + dist[k][j][1]);
			}

		for (auto[a, b, idx, t] : query[k])
			resp.push_back({idx, dist[a][b][t]});
	}

	sort(all(resp));
	for (auto[a, b] : resp)
		cout << (b==INF?-1:b) << endl;
}









