#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (710)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, n, m, tab[MAXN][MAXN];
vector<ii> cores[MAXN*MAXN];

int cmp(ii a, ii b)
{
	return a.second < b.second;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> tab[i][j];
				cores[tab[i][j]].push_back({i, j});
			}
		}	

		int maior = 1, resp = 0;
		for (int c = 1; c <= n*m; c++)
		{
			int flag = 0;
			if (!cores[c].size()) continue;
			sort(all(cores[c]));
			for (int i = 1; i < cores[c].size(); i++)
				flag |= (cores[c][i].first == cores[c][i-1].first && cores[c][i].second-cores[c][i-1].second == 1);
			sort(all(cores[c]), cmp);
			for (int i = 1; i < cores[c].size(); i++)
				flag |= (cores[c][i].second == cores[c][i-1].second && cores[c][i].first-cores[c][i-1].first == 1);

			if (flag) resp += 2, maior = 2;
			else resp++;
			cores[c].clear();
		}

		cout << resp - maior << endl;
	}
}
