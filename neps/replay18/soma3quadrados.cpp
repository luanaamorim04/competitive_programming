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

int n, ok;
vector<int> v, c;

int bb(int x)
{
	int ini = 0, meio, fim = sz(c)-1;
	while (ini <= fim)
	{
		meio = ini + ((fim-ini)>>1);
		if (c[meio]==x) return 1;
		else if (c[meio] > x) fim = meio - 1;
		else ini = meio + 1;
	}

	return 0;
}

int main()
{_
	cin >> n;
	for (int i = 0; i*i <= n; i++)
		v.push_back(i*i);

	for (int i = 0; i < sz(v); i++)
		for (int j = 0; j < sz(v); j++)
			c.push_back(v[i]+v[j]);

	sort(all(c));

	for (int i = 0; i*i <= n; i++)
		ok |= bb(n-(i*i));

	cout << (ok ? "YES" : "NO") << endl;
}













