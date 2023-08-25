#include <iostream>
#define MAXN (int) (3e5 + 10)
#define ii pair<int, int>
#define all(x) x.begin(), x.end()

using namespace std;

int t, n, k, arr[MAXN];
vector<ii> v;

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			v.push_back({-(arr[i]%k), i});
		}

		sort(all(v));

		for (auto[a, b] : v)
		{
			cout << b << ' ';
		}
		cout << endl;

	}
}