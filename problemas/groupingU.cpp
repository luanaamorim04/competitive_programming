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
#define MAX (int) (1e6)
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
		
ll peso[MAX], n, tab[20][20], dp[MAX];

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> tab[i][j];

	for (int mask = 0; mask < (1<<n); mask++)
		for (int i = 0; i < n; i++)
		{
			if (!(mask&(1<<i))) continue;
			for (int j = i+1; j < n; j++)
				if (mask&(1<<j)) peso[mask] += tab[i][j];
		}

	for (int mask = (1<<n) - 1; mask >= 0; mask--)
	{
		int m = (mask^((1<<n) - 1));
		for (int i = m; i > 0; i = (i-1)&m)
			dp[mask] = max(dp[mask], dp[mask|i] + peso[i]);
	}

	cout << dp[0] << endl;
}








