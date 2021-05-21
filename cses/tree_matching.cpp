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
#define MAX (int) (2e5 + 5)
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

queue<int> fila;
vector<int> grafo[1<<20];
int pode[1<<20], n, grau[1<<20], ans, a, b;

int main()
{_
	cin >> n;
	for (int i = 1; i < n; i++) 
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
		grau[a]++, grau[b]++;
	}

	for (int i = 1; i <= n; i++) if (grau[i] == 1) fila.push(i), grau[i]--;

	while (!fila.empty())
	{
		int u = fila.front(); fila.pop();
		for (int v : grafo[u])
		{
			grau[v]--;
			if (!pode[v] && !pode[u])
			{
				pode[v] = pode[u] = 1;
				ans++;
			}
			if (grau[v] == 1) fila.push(v);
		}
	}

	cout << ans << endl;
}
















