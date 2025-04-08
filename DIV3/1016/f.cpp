#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(1e3 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)
#define BASE 37
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int t, n, m;
string c[MAXN], s[MAXN][MAXN];

int32_t main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		int resp = 0;
		vector<set<int> > pos(n+1);
		for (int i = 0; i < n; i++)
			cin >> c[i];
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> s[i][j];
				if (s[i][j] == c[j]) pos[i].insert(j);
			}
		}

		int qtd = 0;
		while (qtd < m)
		{
			int maior = 0;
			for (int i = 0; i < m; i++)
				if (pos[maior].size() < pos[i].size()) maior = i;

			if (pos[maior].size() == 0) break;
			resp += m-qtd;  
			qtd += pos[maior].size();

			for (int i = 0; i < m; i++)
			{
				if (i == maior) continue;
				for (int j : pos[maior])
				{
					pos[i].erase(j);
				}
			}

			pos[maior].clear();
		}

		if (qtd < m) cout << -1 << endl;
		else cout << resp << endl;
	}

}
