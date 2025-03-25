#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
#define BASE 37
#define MAXL 20
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int t, n;

int32_t main()
{_
	cin >> t;
//	vector<int> v;
//	n = 12;
//	for (int i = 1; i <= n; i++)
//		v.push_back(i);
//	
//	int ok = 0;
//	do
//	{	
//		int okk = 1;
//		for (int shift = 0; shift < n; shift++)
//		{
//			int tmp = 0;
//			for (int i = 1; i <= n; i++)
//				tmp += (v[(i-1+shift)%n] == i);
//			okk &= (tmp == 1);
//		}
//		ok |= okk;
//		if (okk)
//		{
//			for (int i : v)
//				cout << i << endl;
//			break;
//		}
//	} while (next_permutation(all(v)));
//	cout << ok << endl;
//
	while (t--)
	{
		cin >> n;
		if ((n%2 == 0))
			cout << -1 << endl;
		else
		{
			for (int i = 1; i <= n; i += 2)
				cout << i << ' ';
			for (int i = 2; i <= n; i += 2)
				cout << i << ' ';
			cout << endl;
		}
	}
}
