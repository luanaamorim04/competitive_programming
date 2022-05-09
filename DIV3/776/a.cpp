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

int t, resp;
string a, b;

int main()
{_
	cin >> t;
	while (t--)
	{
		resp = 0;
		cin >> a >> b;
		if (sz(a) < sz(b))
		{
			cout << "NO" << endl;
			continue;
		}

		for (int i = 0; i < sz(a); i++)
		{
			int pode = 1;
			for (int j = 0; j < sz(b); j++)
			{
				pode &= (a[i+j] == b[j]); 
			}

			if (pode)
			{
				if (!(i&1) && !(((sz(a)-1)-(i+sz(b)-1))&1))
				{
					resp = 1;
				}
			}
		}

		cout << (resp?"YES":"NO") << endl;
	}
}




