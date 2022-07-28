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
#define dbug(x) cout << (#x) << " -> " << x << endl
#define ll long long
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

ll n, a, b, pref[MAX], resp;
pair<ll, ll> v[MAX];
tuple<ll, ll, ll> tmp[MAX];

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i].second >> v[i].first;

	sort(v, v+n+1);
	pref[0] = resp = INF;
	for (int i = 1; i <= n; i++)
		pref[i] = min(v[i].second, pref[i-1]);

	for (int i = 2; i <= n; i++)
		tmp[i] = {v[i].first, pref[i-1] + v[i].first + v[i].second, v[i].second};
	
	sort(tmp, tmp+n+1);
	pref[1] = INF;
	for (int i = 2; i <= n; i++)
	{
		auto[a, b, c] = tmp[i];
		pref[i] = min(b, pref[i-1]);
	}

	for (int i = 3; i <= n; i++)
	{
		auto[a, b, c] = tmp[i];
		resp = min(resp, a + c + pref[i-1]);
	}
	
	cout << resp << endl;
}












