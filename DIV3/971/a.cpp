#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9 + 10)
#define ii pair<int, int> 
#define all(x) x.begin(), x.end()

using namespace std;

int resp, a, b, t, n, m;
string s[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> s[i];

		for (int i = n-1; i >= 0; i--)
		{
			for (int j = 0; j < s[i].size(); j++)
				if (s[i][j] == '#')
				{
					cout << j+1 << ' ';
					break;
				}
		}

		cout << endl;
	}
}
