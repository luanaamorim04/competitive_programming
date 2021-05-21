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

ll n, k;

ll f(ll x)
{
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += min(n, (x/i));
	return ans;
}

int main()
{_
	cin >> n;
	k = ((n*n)>>1) + 1;
	ll ini = 1, meio, fim = n*n;
	while (ini <= fim)
	{
		meio = ini + ((fim-ini)>>1);
		if (f(meio) >= k) fim = meio - 1;
		else ini = meio + 1;
	}

	cout << fim + 1 << endl;
}














