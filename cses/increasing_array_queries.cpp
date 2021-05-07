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

ll arr[1<<20], resp[1<<20], psa[1<<20];
int st[1<<20], a, b, n, m, maior[1<<20];

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = i;
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = ((arr[st[esq(idx)]] > arr[st[dir(idx)]]) ? st[esq(idx)] : st[dir(idx)]);
}

int query(int idx, int i, int j, int l, int r)
{
	if (i >= l && j <= r) return st[idx];
	if (i > r || j < l) return 0;
	int mid = ((i+j)>>1);
	int x = query(esq(idx), i, mid, l, r);
	int y = query(dir(idx), mid+1, j, l, r);
	return ((arr[x] > arr[y]) ? x : y);
}

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
	{
		cin >> arr[i];
		psa[i] = psa[i-1] + arr[i];
	}

	build(1, 1, n);

	arr[n+1] = INF;
	for (int i = n; i >= 1; i--)
	{
		maior[i] = i+1;
		while (arr[maior[i]] < arr[i]) maior[i] = maior[maior[i]];
		resp[i] = resp[maior[i]] + ((arr[i]*(maior[i]-i-1)) - (psa[maior[i]-1]-psa[i]));
	}

	while (m--)
	{
		cin >> a >> b;
		ll maxn = query(1, 1, n, a, b);
		ll dif = (maior[maxn]-b-1);
		cout << resp[a] - ((dif*arr[maxn]) - (psa[maior[maxn]-1] - psa[b])) - resp[maior[maxn]] << endl;
	}
}











