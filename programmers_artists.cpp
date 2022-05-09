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

ll a, b, n, resp, q1, q2, k1, k2, idx;
vector<par> v;

int main()
{_
	cin >> a >> b >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> k1 >> k2;
		v.emplace_back(k1-k2, -k1);
		resp += k1;
	}

	sort(all(v));
	q1 = n;

	while (q1 != a || q2 != b)
	{
		if (q2 < b) 
		{
			q2++;
			resp -= (v[idx].first);
		}
		else if (q1 > a)
		{
			resp -= (-v[idx].second);
		}
		idx++;
		q1--;
	}

	cout << resp << endl;
}













