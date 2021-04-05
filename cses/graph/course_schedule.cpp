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
#define ll long long
#define INF (1e9)
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> grafo[1<<20], resp;
int n, m, a, b, grau[1<<20];
queue<int> fila;

int main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grau[b]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!grau[i]) fila.push(i), resp.push_back(i);
	}

	while (!fila.empty())
	{
		int u = fila.front(); fila.pop();
		for (int i = 0; i < grafo[u].size(); i++)
		{
			int v = grafo[u][i];
			grau[v]--;
			if (!grau[v]) 
			{
				fila.push(v);
				resp.push_back(v);
			}
		}
	}

	if (resp.size() != n) cout << "IMPOSSIBLE" << endl;
	else
	{
		for (int i = 0; i < resp.size(); i++) cout << resp[i] << ' ';
		cout << endl;
	}



}
