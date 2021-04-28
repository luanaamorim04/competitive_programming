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
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, pos[1<<20], resp[4], t, arr[1<<20], ft[1<<20], ft1[1<<20];
set<int> s;

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

void update(int idx, ll val)
{
	while (idx <= n)
	{
		ft[idx] += val;
		idx += lsb(idx);
	}
}

ll query1(int idx)
{
	ll ans = 1;
	while (idx > 0)
	{
		ans = max(ans, ft1[idx]);
		idx -= lsb(idx);
	}
	return ans;
}

void update1(int idx, ll val)
{
	while (idx <= n)
	{
		ft1[idx] = max(ft1[idx], val);
		idx += lsb(idx);
	}
}

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		pos[arr[i]] = i;
	}

	for (int i = n; i >= 1; i--)
	{
		update(arr[i] + 1, 1);
		resp[0] += query(arr[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		resp[2] = max(query1(arr[i]), resp[2]);
		update1(arr[i] + 1, query1(arr[i]) + 1);
	}

	resp[2] = n - resp[2];

	ll tmp = n; resp[3] = n; 
	for (int i = pos[n]; i >= 1; i--)
		if (tmp == arr[i]) tmp--, resp[3]--;

	for (int i = 1; i <= n; i++)
	{
		if (pos[i] != i) resp[1]++;
		swap(arr[pos[i]], arr[i]);
		pos[arr[pos[i]]] = pos[i];
		pos[i] = i;
	}

	for (ll r : resp) cout << r << ' ';
	cout << endl;
}











