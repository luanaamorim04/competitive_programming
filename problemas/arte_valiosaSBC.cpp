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

struct circulo
{
	ll r, x, y;
};

ll n, m, k, comp[MAX], idx;
ll esq[MAX], dir[MAX], up[MAX], down[MAX], pai[MAX];
circulo c[MAX];

ll dist(circulo a, circulo b)
{
	return ((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y));
}

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int i, int j)
{
	if (find(i) == find(j)) return;
	i = find(i);
	j = find(j);
	esq[j] = min(esq[i], esq[j]);
	dir[j] = max(dir[i], dir[j]);
	up[j] = min(up[j], up[i]);
	down[j] = max(down[j], down[i]);
	pai[i] = j;
}

int main()
{_
	cin >> m >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		pai[i] = i;
		cin >> c[i].x >> c[i].y >> c[i].r;
		dir[i] = c[i].x + c[i].r;
		esq[i] = c[i].x - c[i].r;
		down[i] = c[i].y + c[i].r;
		up[i] = c[i].y - c[i].r;
	}

	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			if (dist(c[i], c[j]) <= (c[i].r+c[j].r)*(c[i].r+c[j].r))
				join(i, j);

	int ok = 1;
	for (int i = 1; i <= k; i++)
	{	
		if (esq[i] <= 0 && up[i] <= 0) ok = 0;
		if (dir[i] >= m && down[i] >= n) ok = 0;
		if (esq[i] <= 0 && dir[i] >= m) ok = 0;
		if (up[i] <= 0 && down[i] >= n) ok = 0;
	}

	cout << (ok ? "S" : "N") << endl;
}	

















