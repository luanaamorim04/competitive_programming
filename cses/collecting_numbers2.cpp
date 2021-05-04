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

int n, m, a, b, arr[MAX], pos[MAX], ans, c;

int main()
{_
	cin >> n >> m;
	ans = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		pos[arr[i]] = i;
	}

	for (int i = 2; i <= n; i++)
		ans += pos[i-1] > pos[i];

	while (m--)
	{
		cin >> a >> b;

		if (a > b) swap(a, b);

		if (arr[b] == arr[a]+1)
			c = 1;
		else if (arr[a] == arr[b]+1)
			c = 2;
		else
			c = -1;

		if (c != 2) ans -= pos[arr[a]-1] > pos[arr[a]];
		ans -= pos[arr[a]] > pos[arr[a] + 1];
		ans -= pos[arr[b]-1] > pos[arr[b]];
		ans -= pos[arr[b]] > pos[arr[b] + 1];

		swap(pos[arr[a]], pos[arr[b]]);
		swap(arr[a], arr[b]);

		if (c != 1) ans += pos[arr[a]-1] > pos[arr[a]];
		ans += pos[arr[a]] > pos[arr[a] + 1];
		ans += pos[arr[b]-1] > pos[arr[b]];
		ans += pos[arr[b]] > pos[arr[b] + 1];

		cout << ans << endl;
	}
}	














