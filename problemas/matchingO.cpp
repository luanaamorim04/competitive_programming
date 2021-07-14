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
#define MAX (int) (1<<22)
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

int n, tab[21][21];
int memo[21][MAX];

int f(int id, int mask)
{
	if (id == n) return 1;
	int &ans = memo[id][mask];
	if (~ans) return ans;
	ans = 0;
	for (int i = 0; i < n; i++)
		if (tab[id][i] && !(mask&(1<<i))) ans = (ans + f(id + 1, mask|(1<<i))) % MOD;

	return ans;
}

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> tab[i][j];

	memset(memo, -1, sizeof memo);
	cout << f(0, 0) << endl;
}



