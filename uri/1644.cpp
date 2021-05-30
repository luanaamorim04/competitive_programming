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
#define MAXL 35
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

int n, m, up[1<<20][MAXL], x;
string s;

int main()
{_
	while (cin >> n >> m && n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			up[x][0] = i;
		}

		getline(cin, s);
		getline(cin, s);

		for (int i = 1; i < MAXL; i++)
			for (int j = 1; j <= n; j++)
				up[j][i] = up[up[j][i-1]][i-1];

		for (int i = 1; i <= n; i++)
		{
			int tmp = m, k = i, idx = 0;
			while (tmp)
			{
				if (tmp&1) k = up[k][idx];
				tmp>>=1;
				idx++;
			}

			cout << s[k-1];
		}
		cout << endl;
	}
}













