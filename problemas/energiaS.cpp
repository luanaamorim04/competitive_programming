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
#define dbug(x) cout << (#x) << " -> " << x << endl
#define ll long long
#define INF (1e9) + 10
#define MAX (int) (1e6)
#define MOD 1000000007
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, m, q, a, b, c, k, peso[MAX], pai[MAX], tam[MAX], sub[MAX], arr[MAX];
vector<par> grafo[MAX];
vector<ll> psa[MAX];
vector<tuple<ll, ll, ll> > v;

int find(int x)
{
	if (x==pai[x]) return x;
	return find(pai[x]);
}

void join(int a, int b, ll c)
{
	a = find(a), b = find(b);
	if (a == b) return;
	if (tam[a] > tam[b]) swap(a, b);
	tam[b] += tam[a];
	pai[a] = b;
	peso[a] = c;
	sub[b] += sub[a];
	grafo[b].push_back({c, a});
	psa[b].push_back(0);
}

int bb(int idx, ll x)
{
	int ini = 1, meio, fim = sz(grafo[idx])-1;
	while (ini <= fim)
	{
		meio = (ini+fim)>>1;
		if (grafo[idx][meio].first <= x) ini = meio + 1;
		else fim = meio - 1;
	}

	return ini - 1;
}	

int solve(int a, ll q)
{
	while (peso[a] <= q) a = pai[a];
	return psa[a][bb(a, q)] + arr[a];
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
	{
		cin >> arr[i];
		pai[i] = i, tam[i] = 1, peso[i] = INF, sub[i] = arr[i];
		grafo[i].push_back({0, 0});
		psa[i].push_back(0);
	}

	while (m--)
	{
		cin >> a >> b >> c;
		v.push_back({c, a, b});
	}

	sort(all(v));
	for (auto[w, u, v] : v) join(u, v, w);

	for (int i = 1; i <= n; i++)
	{
		sort(all(grafo[i]));
		for (int j = 1; j < sz(grafo[i]); j++)
		{
			psa[i][j] = psa[i][j-1] + sub[grafo[i][j].second];
		}
	}

	cin >> q;
	while (q--)
	{
		cin >> a >> b;
		ll resp = solve(a, k+b);
		k = resp;
		cout << resp << endl;
	}
}











