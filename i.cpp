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
#define MAX (int) (2e3 + 5)
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

int n, m, a, b, grau[MAX], k, dist[MAX][MAX], e[MAX], s[MAX], prox[MAX], resp[MAX], pai[MAX];
vector<par> arr;

int cmp(par a, par b)
{
	return dist[a.first][a.second] < dist[b.first][b.second];
}	

int main()
{_
	while (cin >> n >> m)
	{
		while (m--)
		{
			cin >> a >> b;
			prox[b] = a;
			grau[a]++;
		}

		for (int i = 1; i <= n+1; i++)
		{
			resp[i] = INF;
			pai[i] = i;
		}

		cout << endl;
		ll resp = 0;
		for (int i = 1; i <= n+1; i++)
			if (!grau[i])
			{
				int u = i;
				++k;
				while (prox[u])
				{
					resp += abs(u-prox[u]);
					u = prox[u];
				}

				e[k] = i;
				s[k] = u;
				cout << k << ' ' << i << ' ' << u << endl;
			} 

		cout << resp << endl;

		for (int i = 0; i <= k; i++)
			for (int j = 0; j <= k; j++)
			{
				arr.push_back({i, j});
				dist[i][j] = abs(s[i]-e[j]);
				W(dist[i][j]);
			}

		sort(all(arr), cmp);
		for (int i = 0; i < sz(arr); i++)
		{
			int a = arr[i].first;
			int b = arr[i].second;
			if (find(a)==find(b)) continue;
			join(a, b);
			resp += dist[a][b];
		}

		cout << resp << endl;
	}
}










