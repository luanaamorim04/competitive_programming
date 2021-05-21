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
#define K 300
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

struct Query
{
	int a, b, idx;
};

Query q[1<<20];
vector<int> arr, grafo[1<<20];
int pos[1<<20], id, id2, resp[1<<20], freq[1<<20], cor[1<<20], ans, a, b, n, maxn;
map<int, int> mapa;

void dfs(int u, int p)
{
	arr.push_back(cor[u]);
	pos[u] = id++;
	for (int v : grafo[u])
		if (v != p) dfs(v, u);
	arr.push_back(cor[u]);
	q[id2++] = {pos[u], id++, u};
}

int cmp(Query q1, Query q2)
{
	if (q1.a/K != q2.a/K) return q1.a < q2.a;
	return q1.b < q2.b;
}

void add(int idx)
{
	ans += !freq[arr[idx]];
	freq[arr[idx]]++;
}

void remove(int idx)
{
	freq[arr[idx]]--;
	ans -= !freq[arr[idx]];
}

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> cor[i];
		if (!mapa.count(cor[i])) mapa[cor[i]] = maxn++;
		cor[i] = mapa[cor[i]];
	}

	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	dfs(1, 0);

	sort(q, q+n, cmp);

	int ini = 0, fim = -1;
	for (int i = 0; i < n; i++)
	{
		while (ini < q[i].a)
			remove(ini++);
		while (ini > q[i].a)
			add(--ini);
		while (fim < q[i].b)
			add(++fim);
		while (fim > q[i].b)
			remove(fim--);


		resp[q[i].idx] = ans;
	}

	for (int i = 1; i <= n; i++)
		cout << resp[i] << ' ';
	cout << endl;
}









