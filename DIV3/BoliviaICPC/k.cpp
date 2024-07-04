#include <iostream>
#include <queue>
#define MAXN (int) (1e3 + 10)
#define ii pair<int, int> 

using namespace std;

int n, m, tab[MAXN][MAXN], a, b, vis[MAXN][MAXN];
char c;

int dijkstra(int a, int b)
{
	queue<ii> fila;
	fila.push({a, b});
	int resp = 0;
	vis[a][b] |= 1;

	while (!fila.empty())
	{
		auto[a, b] = fila.front(); fila.pop();
		resp += tab[a][b];
		if (vis[a][b] == 3) continue;


		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
			{
				if (i && j) continue;
				if (vis[a+i][b+j] == 1) continue;
				fila.push({a+i, b+j});

				vis[a+i][b+j] |= 1;
			}
	}

	return resp;
}

int32_t main()
{
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				cin >> c;
				if (c >= '0' && c <= '9')tab[i][j] = c - '0';
				if (c == 'S') a = i, b = j;
				if (vis[i][j]) continue;

				if (c == '#') vis[i][j] = 1;
				else if (c == 'T') 
					vis[i+1][j] = vis[i-1][j] = vis[i][j-1] = vis[i][j+1] = 2, vis[i][j] = 1;

				tab[i][0] = tab[i][m+1] = -2;
				tab[0][j] = tab[n+1][j] = -2;
			}

		cout << dijkstra(a, b) << endl;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				vis[i][j] = tab[i][j] = 0;
	}
}
