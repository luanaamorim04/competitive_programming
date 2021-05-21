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
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> grafo[1<<20], r;
int grau[MAX], n, m, a, b;
priority_queue<int> fila;

int main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		grafo[b].push_back(a);
		grau[a]++;
	}

	for (int i = 1; i <= n; i++)
		if (!grau[i]) fila.push(i);

	while (!fila.empty())
	{
		int u = fila.top(); fila.pop();
		r.push_back(u);
		for (int v : grafo[u])
			if (!(--grau[v])) fila.push(v);
	}

	for (int i = r.size() -1; i >= 0; i--)
		cout << r[i] << ' ';

	cout << endl;
}
