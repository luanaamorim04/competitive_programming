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
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll t, n, m, tot;
par resp[MAX];
tuple<ll, ll, ll> arr[MAX];

int main()
{_
	cin >> t;
	while (t--)
	{
		tot = 0;
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			ll a, b;
			cin >> b >> a;
			arr[i] = {a, b, i+1};
		}

		sort(arr, arr+m);

		for (int i = 0; i < n<<1; i++)
		{
			auto[a, b, c] = arr[i];
			tot += a;
			resp[i] = {b, c};
		}

		sort(resp, resp+(n<<1));

		cout << tot << endl;
		for (int i = 0; i < n; i++)
			cout << resp[i].second << ' ' << resp[(n<<1)-1-i].second << endl;
		cout << endl;
		
	}
}










