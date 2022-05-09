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

ll n, m, arr[8][MAX], a, b, c, resp;

int main()
{_
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		for (int j = 0; j < 8; j++)
			arr[j][i] = (a*((j&1) ? 1 : -1)) + (b*((j&2) ? 1 : -1)) + (c*((j&4) ? 1 : -1));
	}

	for (int i = 0; i < 8; i++)
		sort(arr[i], arr[i]+n, greater<ll>());

	for (int j = 0; j < 8; j++)
	{
		ll t = 0;
		for (int i = 0; i < m; i++)
			t += arr[j][i];
		
		resp = max(resp, t);
	}

	cout << resp << endl;
}










