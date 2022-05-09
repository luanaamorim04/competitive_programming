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
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a, b, c, last;

int main()
{_
	cin >> a >> b >> c;
	if (a > b) last = 1;
	while (c)
	{
		if (last) 
		{
			cout << 0;
			a--;
		}
		else
		{
			cout << 1;
			b--;
		}
		last ^= 1;
		c--;
	}

	if (last && !b) while (a--) cout << 0;
	else if (!last && !a) while (b--) cout << 1;
	else
	{
		if (last) swap(a, b);
		while (a--) cout << last;
		while (b--) cout << (last^1);
	}

	cout << endl;
}








