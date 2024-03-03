#include <iostream>
#include <vector>
#include <set>
#define MAXN (int) (2e5 + 10)
#define INF 1e9
#define all(x) x.begin(), x.end()
#define int long long
#define ii pair<int, int>

using namespace std;

int n, m, t, k, a, b, l;

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> l;
		int A = 1, B = b, resp = 0;
		set<int> s;
		for (int i = 0; i < 30; i++)
		{
			B = 1;
			for (int j = 0; j < 30; j++)
			{
				if (A*B > l) break;
				if (l % (A*B) == 0) 
				{
					s.insert(l/(A*B));
				}
				B *= b;
			}
			A *= a;
			if (A > l) break;
		}

		cout << s.size() << endl;
	}
}
