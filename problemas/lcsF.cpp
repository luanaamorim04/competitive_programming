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

string a, b, resp, tmp;
int maxn, dp[3001][3001];
par last[3001][3001];

int main()
{_
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		for (int j = b.size() - 1; j >= 0; j--)
		{
			if (a[i] == b[j]) 
			{
				dp[i][j] = dp[i + 1][j + 1] + 1;
				last[i][j] = {i + 1, j + 1};
			} 
			else if (dp[i + 1][j] > dp[i][j + 1])
			{
				dp[i][j] = dp[i + 1][j];
				last[i][j] = {i + 1, j};
			}
			else
			{
				dp[i][j] = dp[i][j + 1];
				last[i][j] = {i, j + 1};
			}
		}
	}

	int x = 0, y = 0, ok = 0;
	while ((x || y) || !ok)
	{
		if (x == sz(a) || y == sz(b)) break;
		if (a[x] == b[y]) resp += a[x];
		auto[i, j] = last[x][y];
		x = i, y = j;
		ok = 1;
	}
	cout << resp << endl;
}










