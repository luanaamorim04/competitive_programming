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
#define MAX (int) (2e3 + 5)
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

string a, b, c;
int n, ok, memo[MAX][MAX];

int f(int u, int v)
{
	if (u+v==sz(c)) return 1;
	int resp = 0;
	if (~memo[u][v]) return memo[u][v];

	if (u<sz(a) && c[u+v]==a[u]) resp |= f(u+1, v);
	if (v<sz(b) && c[u+v]==b[v]) resp |= f(u, v+1);

	return memo[u][v] = resp;
}

int main()
{_
	cin >> n;
	for (int t = 1; t <= n; t++)
	{
		cin >> a >> b >> c;
		memset(memo, -1, sizeof memo);
		cout << "Data set " << t << ": " << (f(0, 0)?"yes":"no") << endl;
	}
}












