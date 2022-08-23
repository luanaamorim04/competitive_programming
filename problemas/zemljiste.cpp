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
#define MAX (int) (505)
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

ll n, m, a, b, tab[MAX][MAX], psa[MAX][MAX], sum, ans;

int main()
{_
	cin >> n >> m >> a >> b;
	if (a < b) swap(a, b);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> tab[i][j];
			psa[i][j] = psa[i-1][j] + tab[i][j];
		}
	}

	/*
		ini -> 1 1 1
			   1 1 1
		fim -> 1 1 1

		1 1 1
		2 2 2
		3 3 3

		psa[i][j] =
		psa[r][fim] - psa[r][ini-1];

	*/

	ans = INF;
	for (int ini = 1; ini <= n; ini++)
	{
		for (int fim = ini; fim <= n; fim++)
		{
			int l = 1, r = 1;
			sum = psa[fim][1] - psa[ini-1][1];
			while (r <= m)
			{
				ans = min(ans, abs(sum-a) + abs(sum-b));
				while (sum > a && l <= r)
				{
					sum -= psa[fim][l] - psa[ini-1][l], l++;
					ans = min(ans, abs(sum-a) + abs(sum-b));
				} 
				
			 	r++;
			 	sum += psa[fim][r] - psa[ini-1][r];
			 	ans = min(ans, abs(sum-a) + abs(sum-b));
				
			}
		}
	}

	cout << ans << endl;
}












