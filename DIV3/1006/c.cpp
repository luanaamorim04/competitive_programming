#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, n;
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		int x;
		cin >> n >> x;
		int idx = 0, curr = 0;
		vector<int> resp;
		while (idx < n-1 && (idx|x) == x)
		{
			curr |= idx;
			cout << idx++ << ' ';
		}
		if ((x^curr) == 0 && (idx|x) == x) cout << idx;
		else cout << (x^curr);

		cout << ' ';
		idx++;
		while (idx < n)
		{
			cout << 0 << ' ';
			idx++;
		}
		cout << endl;

	}
}
