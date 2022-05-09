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
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, p[1<<20], ok;
string s;
char last;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		ok = 1;
		s += '*';
		last = '*';
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != last)
			{
				if (p[s[i]]) ok = 0;
				p[s[i]] = 1;
				last = s[i];
			}
		}

		for (int i = 0; i < s.size(); i++) p[s[i]] = 0;

		cout << (ok ? "YES" : "NO") << endl;
	}
}




