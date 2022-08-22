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

int n, t, a, b, r1, r2, last[100];

int main()
{_
	cin >> n;
	for (int i = 1; i <= 20; i++) last[i] = -INF;
	while (n--)
	{
		cin >> t >> a >> b;
		if (a <= 4)
		{
			r1 += 100;
			if (last[a] >= t-10) r1 += 50;
		}
		else
		{
			r2 += 100;
			if (last[a] >= t-10) r2 += 50;
		}
		last[a] = t;
	}

	cout << r1 << ' ' << r2 << endl;
}



