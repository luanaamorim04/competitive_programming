#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp make_pair

const int N = 1000;
const int dir[][2] = {1,0,-1,0,0,1,0,-1};
int vet[N][N], n, m, vis[N][N];
pair<int, int> s, e;

int bfs()
{
	queue<pair<int, int> > que;
	vis[s.F][s.S] = 1;
	que.push(s);
	while (!que.empty())
	{
		pair<int, int> p = que.front();
		que.pop();
		for (int d = 0; d < 4; ++d)
		{
			pair<int, int> q = make_pair(p.F+dir[d][0], p.S+dir[d][1]);
			if (q.F == -1 || q.F == n || q.S == -1 || q.S == m) continue;
			if (vis[q.F][q.S] || vet[q.F][q.S] == 0) continue;
			vis[q.F][q.S] = vis[p.F][p.S]+1;
			que.push(q);
		}
	}
	return vis[e.F][e.S];
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> vet[i][j];
			if (vet[i][j] == 3) s = mp(i, j);
			if (vet[i][j] == 2) e = mp(i, j);
		}
	}
	cout << bfs() << endl;
}

