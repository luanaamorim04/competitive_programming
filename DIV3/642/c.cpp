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

ll idx, t, n, resp;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n;
		idx = 1;
		ll lado = 1;
		resp = 0;
		n *= n;
		n--;
		while (n)
		{
			n -= ((lado*4) + 4);
			resp += idx*(((lado*4) + 4));
			idx++;
			lado += 2;
		}

		cout << resp << endl;
	}
}





