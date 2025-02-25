#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (710)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, n, m, tab[MAXN][MAXN], vis[MAXN][MAXN];

int flood(int a, int b, int cor)
{
	if (a < 1 || b < 1 || a > n || b > m) return 0;
	if (tab[a][b] != cor) return 0;
	if (vis[a][b]) return 0;
	vis[a][b] = 1;
	int resp = 1;
	resp += flood(a+1, b, cor);
	resp += flood(a, b+1, cor);
	resp += flood(a-1, b, cor);
	resp += flood(a, b-1, cor);
	return resp;
}
		vector<ii> cores[MAXN*MAXN];
		vector<int> comps[MAXN*MAXN];

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
				vis[i][j] = 0;
				cin >> tab[i][j];
				cores[tab[i][j]].push_back({i, j});
			}
		}	

		int maior = 0, resp = 0;
		for (int c = 1; c <= n*m; c++)
		{
			if (cores[c].size() < 1) continue;
			int custo = 0, flag = 0, flag1 = 0;
			for (auto[i, j] : cores[c])
			{
			//	cout << "cor: " << c << endl;
				if (!vis[i][j]) 
				{
					int val = flood(i, j, c);
					if (val != 1 && !flag1) flag1 = 1; 
					if (val == 1 && !flag) flag = 1;
				}
			}

			if (flag1) custo = 2;
			else if (flag) custo = 1;
			
			resp += custo;
			if (custo > maior) maior = custo;
			cores[c].clear();


		}

		//cout << maior << endl;
		cout << resp - maior << endl;
	}
}

