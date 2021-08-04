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
#define INF (1e18)
#define MAX (int) (2e5 + 5)
#define EPS 1e-9
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

struct tpoint
{
	int x, y, r;
};

tpoint arr[130];
ll n, q, a, b, ans;
double dist[130][130], d;

int main()
{_
	while (cin >> n && n)
	{
		for (int i = 1; i <= n; i++)
			cin >> arr[i].x >> arr[i].y >> arr[i].r;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d = hypot((arr[i].x-arr[j].x), (arr[i].y-arr[j].y));
				dist[i][j] = (arr[i].r >= d ? d : INF);
			}
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		cin >> q;
		while (q--)
		{
			cin >> a >> b;
			ans = dist[a][b];
			cout << (ans != INF ? ans : -1LL) << endl;
		}
	}
}















