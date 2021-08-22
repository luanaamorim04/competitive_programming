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
#define ll unsigned long long
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

ll dist[505][505], arr[505], n, resp, vis[505];
vector<ll> v;

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> dist[i][j];

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int k = n; k >= 1; k--)
	{
		vis[arr[k]] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][arr[k]] + dist[arr[k]][j]);

		resp = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (vis[i] && vis[j]) resp += dist[i][j];

		v.push_back(resp);
	}

	reverse(all(v));
	for (ll i : v)
		cout << i << ' ';
	cout << endl;
}










