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

int resp[MAX], vertice[MAX], total, prox[MAX], val[MAX], r, st[MAX<<2], st1[MAX<<2], lazy[MAX<<2];
par intervalo[MAX];
vector<int> grafo[MAX];
vector<par> ans;

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = 1;
		st1[idx] = val[i];
		return;
	}
	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = st[esq(idx)] + st[dir(idx)];
	st1[idx] = max(st1[esq(idx)], st1[dir(idx)]);
}

void push(int idx, int i, int j)
{
	if (!lazy[idx]) return;
	lazy[idx] = 0;
	st[idx] = 0;
	if (i != j)
	{
		lazy[esq(idx)] = 1;
		lazy[dir(idx)] = 1;
	}
	lazy[idx] = 0;
}

void update(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx] = 1;
		push(idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r);
	update(dir(idx), mid+1, j, l, r);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

int posicao(int idx, int i, int j, int pos)
{
	push(idx, i, j);
	if (i==j) return i;
	int mid = (i+j)>>1;
	if (pos <= st[esq(idx)]) return posicao(esq(idx), i, mid, pos);
	return posicao(dir(idx), mid+1, j, pos-st[esq(idx)]);
}

int maior(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st1[idx];
	int mid = (i+j)>>1;
	int x = maior(esq(idx), i, mid, l, r);
	int y = maior(dir(idx), mid+1, j, l, r);
	return max(x, y);
}

void bfs(int n)
{
	int u = total, p = 0;
	queue<par> fila;
	fila.push({u, p});
	while (!fila.empty())
	{
		auto[u, p] = fila.front(); fila.pop();
		for (int v : grafo[u])
		{
			if (v==p) continue;
			resp[v] = max(resp[v], 1+resp[u]);
			fila.push({v, u});
		}

		if (maior(1, 1, n, intervalo[u].first, intervalo[u].second-1) > r) resp[u] = -1;
		ans.push_back({resp[u], -intervalo[u].first});
	}
}

int GetBestPosition(int n, int c, int R, int *k, int *a, int *b)
{
	r = R;
	total = n;
	for (int i = 1; i <= n; i++) 
	{
		vertice[i] = i;
		prox[i] = i+1;
		intervalo[i] = {i, i};		
		if (i<n) val[i] = k[i-1];
	}

	build(1, 1, n);

	for (int i = 0; i < c; i++)
	{
		++total;
		int l = posicao(1, 1, n, a[i]);
		int r = posicao(1, 1, n, b[i]);
		int u = l;
		while (u != r)
		{
			grafo[vertice[u]].push_back(total);
			grafo[total].push_back(vertice[u]);
			u = prox[u];
		}
		grafo[vertice[u]].push_back(total);
		grafo[total].push_back(vertice[u]);

		vertice[l] = total;
		prox[l] = prox[r];
		intervalo[total] = {l, r};
		update(1, 1, n, l+1, r);
	}

	bfs(n);
	sort(all(ans), greater<par>());

	return -ans[0].second;	
}






















