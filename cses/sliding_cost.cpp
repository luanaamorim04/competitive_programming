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

struct tree
{
	ll soma_tot, soma_freq;
};

tree st[1<<20];
map<int, int> mapa;
ll n, k, arr[1<<20], cp[1<<20], t;

tree combine(tree esq, tree dir)
{
	tree ans;
	ans.soma_freq = esq.soma_freq + dir.soma_freq;
	ans.soma_tot = esq.soma_tot + dir.soma_tot;
	return ans;
}

int bb(int idx, int i, int j, int tot)
{
	if (i == j) return i;
	int mid = ((i+j)>>1);
	if (st[esq(idx)].soma_freq + tot <= t) return bb(dir(idx), mid+1, j, tot + st[esq(idx)].soma_freq);
	return bb(esq(idx), i, mid, tot);
}

tree query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l || l > r) return {0, 0};
	if (i >= l && j <= r) return st[idx];

	int mid = ((i+j)>>1);
	tree x = query(esq(idx), i, mid, l, r);
	tree y = query(dir(idx), mid+1, j, l, r);
	return combine(x, y);
}

void update(int idx, int i, int j, int pos, ll val)
{
	if (i == j)
	{
		st[idx].soma_freq += val;
		st[idx].soma_tot += (cp[i]*val);
		return;
	}

	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = combine(st[esq(idx)], st[dir(idx)]);
}

ll solve()
{
	int meio = bb(1, 1, n, 0);

	tree menor = query(1, 1, n, 1, meio-1);
	tree maior = query(1, 1, n, meio + 1, n);

	ll resp = (menor.soma_freq*cp[meio]) - menor.soma_tot;
	resp += maior.soma_tot - (maior.soma_freq*cp[meio]);
	return resp;
}

int main()
{_
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		cp[i] = arr[i];
	}

	t = ((k+1)>>1) - 1;
	sort(cp+1, cp+1+n);

	for (int i = 1; i <= n; i++) mapa[cp[i]] = i;
	for (int i = 1; i <= k; i++) update(1, 1, n, mapa[arr[i]], 1);

	cout << solve() << ' ';

	for (int i = k+1; i <= n; i++)
	{
		update(1, 1, n, mapa[arr[i]], 1);
		update(1, 1, n, mapa[arr[i-k]], -1);
		cout << solve() << ' ';
	}

	cout << endl;
}




















