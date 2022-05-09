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
#define ll long long
#define INF (1e9)
#define MAX 501
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, x, s, l, r, memo[(MAX*MAX)>>1][MAX][MAX], usei[MAX], qnt;
vector<int> resp;

int f(int n, int k, int idx)
{
	if (n < 0) return 0;
	if (n == 0) return k==0;
	for (int i = idx; i <= x; i++)
	{
		if (f(n-i, k-1, idx+1))
		{
			usei[i] = 1;
			resp.push_back(i);
			return 1;
		}
	}

	return  0;
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> x >> l >> r >> s;
		qnt = r-l+1;
		l--;
		if (!f(s, qnt, 1))
		{
			cout << -1 << endl;
			continue;
		}

		for (int i = 1; i <= x; i++)
		{
			if (!usei[i] && l) l--, usei[i] = 1, cout << i << ' ';
		}

		for (int i = 0; i < resp.size(); i++)
		{
			cout << resp[i] << ' ';
		}

		for (int i = 1; i <= x; i++)
		{
			if (!usei[i]) cout << i << ' ';
		}

		cout << endl;
		memset(usei, 0, sizeof(usei));
	}
}
