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

int t, n, arr[MAX], op;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n;
		set<par> s;
		s.insert({n, -1});
		op = 1;

		while (!s.empty())
		{
			auto[tam, l] = *s.rbegin();
			s.erase({tam, l});

			l = -l;
			int r = (l+tam-1);
			if (tam&1)
			{
				int idx = ((l+r)>>1);
				arr[idx] = op;
				if (idx != l) s.insert({idx-l, -l});
				if (idx != r) s.insert({r-idx, -(idx+1)});
			}
			else
			{
				int idx = ((l+r-1)>>1);
				arr[idx] = op;
				if (idx != l) s.insert({idx-l, -l});
				if (idx != r) s.insert({r-idx, -(idx+1)});
			}

			op++;
		}

		for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
		cout << endl;
	}
}










