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
#define MAX (int) (2e5 + 5)
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

int n, m, a, b, c, p[MAX], grau[MAX], nivel[MAX], resp, ok;
vector<int> grafo[MAX];
queue<int> fila;

int main()
{_	
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> c >> b;
		b += (n<<1);
		if (~c) 
		{
			grafo[b].push_back(a);
			grau[a]++;
		}
		else
		{
			grafo[a].push_back(b);
			grau[b]++;
		}
	}

	for (int i = 1; i <= (n<<2); i++)
	{
		// cout << grau[i] << endl;
		if (!grau[i])
		{
			// cout << i << endl;
			fila.push(i);
		}
	}

	while (!fila.empty())
	{
		int u = fila.front(); fila.pop();
		resp = max(resp, nivel[u]);
		for (int v : grafo[u])
		{
			grau[v]--;
			if (!grau[v]) 
			{
				nivel[v] = nivel[u] + 1;
				fila.push(v);
			}
		}
	}

	for (int i = 1; i <= (n<<1); i++)
	{
		if (nivel[i] == resp) 
		{
			ok++;
			break;
		}
	}
	for (int i = (n<<1) + 1; i <= (n<<2); i++)
	{
		if (nivel[i] == resp) 
		{
			ok++;
			break;
		}
	}

	resp += (ok > 1);
	cout << resp+1 << endl;
}















