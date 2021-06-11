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
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e3 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, paridade[MAX][MAX][2], vis[MAX<<2], cor[MAX<<2], comp[MAX<<2], k, ini[MAX<<2];
vector<int> grafo[MAX<<2];
string tab[MAX], pos[4];

void build()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			paridade[i][j][0] = paridade[i-1][j][0]^(tab[i][j]=='B');
			paridade[i][j][1] = paridade[i][j-1][1]^(tab[i][j]=='B');
		}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab[i][j] != 'A') continue;

			int esq = paridade[i][j][1];
			int dir = paridade[i][n-1][1]^esq;
			int up = paridade[i][j][0];
			int down = paridade[n-1][j][0]^up;
			if (up == dir) 
			{
				grafo[j].push_back(i + 3*n);
				grafo[i + 3*n].push_back(j);
			}
			if (up == esq)
			{
				grafo[j].push_back(i + 2*n);
				grafo[i + 2*n].push_back(j);
			}

			if (down == dir) 
			{
				grafo[j + n].push_back(i + 3*n);
				grafo[i + 3*n].push_back(j + n);
			}
			if (down == esq)
			{
				grafo[j + n].push_back(i + 2*n);
				grafo[i + 2*n].push_back(j + n);
			}
		}
	}
}

void bfs(int x)
{
	queue<int> fila;
	vis[x] = 1;
	ini[++k] = x;
	fila.push(x);
	while (!fila.empty())
	{
		int u = fila.front(); fila.pop();
		comp[u] = k;
		for (int v : grafo[u])
		{
			if (!vis[v])
			{
				cor[v] = cor[u]^1;
				fila.push(v);
				vis[v] = 1;
			}
		}
	}
}

int solve(string u, string d, string l, string r)
{
	for (int i = 0; i < n; i++)
		if (((u[i]-'0')^paridade[n-1][i][0]) != (d[i]-'0')) return 0;
	for (int i = 0; i < n; i++)
		if (((l[i]-'0')^paridade[i][n-1][1]) != (r[i]-'0')) return 0;

	u += d + l + r;
	for (int i = 0; i < (n<<2); i++)
		if (((u[i]-'0')^(u[ini[comp[i]]]-'0')) != cor[i]) return 0;
	
	return 1;
}

int main()
{_
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> tab[i];	

	build();

	for (int i = 0; i < (n<<2); i++)
		if (!vis[i]) bfs(i);
	
	while (m--)
	{
		for (int i = 0; i < 4; i++) cin >> pos[i];
		cout << (solve(pos[0], pos[1], pos[2], pos[3]) ? "YES" : "NO") << endl;
	}
}














