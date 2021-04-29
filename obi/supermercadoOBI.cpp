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

int n, x[1<<20], y[1<<20], t;

int main()
{_
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];

		sort(x, x+n);
		sort(y, y+n);

		cout << "Teste " << ++t << endl;
		cout << x[(n>>1)] << ' ' << y[(n>>1)] << endl << endl;
	}
}
