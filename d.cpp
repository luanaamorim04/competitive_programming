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
#define MAX (int) (100 + 5)
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

ll t, n, m, tab[MAX][MAX], resp, win[MAX][MAX], qnt, ans[MAX][MAX];
char c;
vector<par> pos;
map<par, int> mapa;

int pode(int a, int b)
{
	return (a >= 1 && b >=1 && a <= n && b <= m);
}

ll brute(int a, int b, int mask, int turn)
{
	if (mask == (1<<sz(pos)) - 1) return !turn;
	for (int k = 0; k < sz(pos); k++)
	{
		auto[i, j] = pos[k];
		if (mask&(1<<k)) continue;
		if (mapa.find({i+1, j+1}) != mapa.end()) mask |= (1<<mapa[{i+1, j+1}]);
		if (mapa.find({i-1, j+1}) != mapa.end()) mask |= (1<<mapa[{i-1, j+1}]);
		if (mapa.find({i+1, j-1}) != mapa.end()) mask |= (1<<mapa[{i+1, j-1}]);
		if (mapa.find({i-1, j-1}) != mapa.end()) mask |= (1<<mapa[{i-1, j-1}]);
		if (!brute(i, j, mask|(1<<k), turn^1)) win[a][b] = 1;
	}	

	if (!win[a][b])
	{
		for (int k = 0; k < sz(pos); k++)
		{
			auto[i, j] = pos[k];
			if (tab[i][j]) mask |= (1<<k);
			if (mask&(1<<k)) continue;
			ans[a][b] += ans[i][j];
		}	
	}
	else
	{
		for (int k = 0; k < sz(pos); k++)
		{
			auto[i, j] = pos[k];
			if (tab[i][j]) mask |= (1<<k);
			if (mask&(1<<k)) continue;
			if (!win[i][j]) ans[a][b] += ans[i][j];
		}
	}

	return ans[a][b];
}

int main()
{_
	cin >> t;
	for (int k = 1; k <= t; k++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> c;
				if (c == '.') tab[i][j] = 1;
				else 
				{
					ans[i][j] = 1;
					pos.push_back({i, j});
					mapa[{i, j}] = sz(pos) - 1;
				}
			}
		}

		for (int i = 0; i < sz(pos); i++)
		{
			auto[a, b] = pos[i];
			resp += brute(a, b, 1<<i, 0);
		}

		cout << "Case #" << k << ": " << resp << endl;
	}
}












