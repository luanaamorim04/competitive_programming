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
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int table[1<<20][21], n, pot, x, q, l, r;

int main()
{_
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> table[i][0];
	
	for (int i = 1; i < 21; i++)
		for (int j = 1; j <= n; j++)
			table[j][i] = min(table[j][i-1], table[j + (1<<(i-1))][i-1]);

	while (q--)
	{
		cin >> l >> r;
		x = r-l+1, pot = 0;
		while ((1<<(pot + 1)) <= x) pot++;
		cout << min(table[l][pot], table[r-(1<<pot)+1][pot]) << endl;
	}
}














