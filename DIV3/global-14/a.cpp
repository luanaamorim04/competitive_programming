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

int t, n, x, arr[1<<20], psa[1<<20], w;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> x;
		w = -1;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			psa[i] = psa[i-1] + arr[i];
			if (psa[i] == x) w = i;
		}

		if (w != -1 && (w == n || arr[n] + psa[w-1] == x))
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
			for (int i = 1; i < n + (w==-1); i++)
			{
				if (i==w)
					cout << arr[n] << ' ';
				cout << arr[i] << ' ';

			}
			cout << endl;
		}
	}
}
