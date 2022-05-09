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

int t, n, k, a[40], b[40], resp;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		resp = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			resp += a[i];
		}
		for (int j = 0; j < n; j++) cin >> b[j];

		sort(b, b+n);
		sort(a, a+n);

		for (int i = 0; i < k; i++)
		{
			if (a[i] < b[n-1-i]) resp += (b[n-1-i] - a[i]);
		}

		cout << resp << endl;
	}
}
