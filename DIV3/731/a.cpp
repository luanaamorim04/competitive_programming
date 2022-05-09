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

int t, a, b, c, d, e, f, k;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c >> d >> e >> f;
		k = 0;
		if (a == c && a == e && f > min(b, d) && f < max(b, d)) k += 2;
		if (b == d && b == f && e > min(a, c) && e < max(a, c)) k += 2;
		cout << abs(a-c) + abs(d-b) + k<< endl;
	}
}
