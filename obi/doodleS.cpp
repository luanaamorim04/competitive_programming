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
#define INF (1e9 + 10)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define ADD ((int) 1e6 + 1)
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
ll n, resp, a, b, p, idx, ft[MAX], k, v, x, y, aa, pode[MAX];
par valor[MAX];
pair<ll, par> arr[MAX];
set<ll> num;
map<ll, int> val;
map<pair<ll, par>, int > id;
 
ll query(int idx)
{
	ll ans = 0;
	while (idx > 0)
	{
		ans += ft[idx];
		idx -= lsb(idx);
	}
	return ans;
}
 
void update(int idx, int val)
{
	while (idx < MAX)
	{
		ft[idx] += val;
		idx += lsb(idx);
	}
}

ll solve(int x)
{		
	ll resp = 0;
	for (int i = 0; i < idx; i++)
	{
		if (pode[i] >= x) continue;
		par line = valor[i];
		if (line.first == INF)
			update(line.second, 1);
		else if (line.first == -INF)
			update(line.second, -1);
		else
			resp += query(line.second) - query(line.first-1);
	}

	return resp;
}
 
int main()
{_
	cin >> n >> k;
	num.insert(0);
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		if (v)
		{
			arr[idx] = {x, {min(y, y+p), max(y, y+p)}};
			id[arr[idx++]] = i;
			y += p;
			num.insert(y);
		}
		else
		{
			arr[idx] = {min(x, x+p), {INF, y}};
			id[arr[idx++]] = i;
			arr[idx] = {max(x, x+p), {-INF, y}};
			id[arr[idx++]] = i;
			x += p;
			num.insert(x);
		}

		v ^= 1;
	}
 
	sort(arr, arr+idx);

	for (ll x : num)
		val[x] = ++aa;
	val[INF] = INF;
	val[-INF] = -INF;

	for (int i = 0; i < idx; i++)
	{
		pode[i] = id[arr[i]];
		valor[i] = {val[arr[i].second.first], val[arr[i].second.second]};
	}

	int ini = 1, meio, fim = n;
	while (ini <= fim)
	{
		meio = ini + ((fim-ini)>>1);
		if (solve(meio) >= k) fim = meio - 1;
		else ini = meio + 1;
	}

	cout << (fim == n ? fim : fim + 1) << ' ' << solve(fim+1) << endl;
}