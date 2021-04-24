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

map<int, int> val;
int ft[1<<20][2], n, arr[1<<20], cp[1<<20], decre[1<<20], cre[1<<20];
ll resp;

int query(int idx, int k)
{
	int ans = 0;
	while (idx > 0)
	{
		ans += ft[idx][k];
		idx -= lsb(idx);
	}
	return ans;
}

void update(int idx, int val, int k)
{
	while (idx <= n)
	{
		ft[idx][k] += val;
		idx += lsb(idx);
	}
}

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		cp[i] = arr[i];
	}

	sort(cp+1, cp+1+n);

	for (int i = 1; i <= n; i++)
		val[cp[i]] = i;

	for (int i = 1; i <= n; i++)
	{
		update(val[arr[i]] + 1, 1, 1);
		cre[i] = (i-1) - query(val[arr[i]], 1);
	}

	for (int i = n; i >= 1; i--)
	{
		update(val[arr[i]] + 1, 1, 0);
		decre[i] = (n-i) - query(val[arr[i]], 0);
		resp += min(decre[i], cre[i]);
	}
	
	cout << resp << endl;
}









