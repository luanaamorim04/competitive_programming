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

set<ll> pos;
ll n, last, resp, dir, now;
char c;

int main()
{_
	cin >> n >> last;
	for (int i = 1; i <= n; i++)
	{
		cin >> c;
		if (c == '#') pos.insert(i);
	}

	dir = 1;
	while (!pos.empty())
	{
		if (dir == 1)
		{
			auto it = pos.upper_bound(last);
			if (it != pos.end()) now = *it, pos.erase(it);
			else now = n+1;
		}
		else
		{
			now = 0;
			auto it = pos.upper_bound(last);
			if (it != pos.begin()) now = *prev(it), pos.erase(prev(it));
		}
	
		resp += abs(last-now);
		last = now;
		dir ^= 1;
	}

	cout << resp << endl;
}	












