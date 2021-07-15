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

string s;
int d;
ll memo[10001][101][2];

ll f(int idx, int m, int igual)
{
	if (idx == sz(s)) return !m;
	ll &ans = memo[idx][m][igual];
	if (~ans) return ans;
	ans = 0;	
	int l = (igual ? (s[idx] - '0') : 9);
	for (int i = 0; i <= l; i++)
		ans = (ans + f(idx+1, ((m + i) % d), (igual && (i == l)))) % MOD;

	return memo[idx][m][igual] = ans;
}

int main()
{_
	cin >> s >> d;
	memset(memo, -1, sizeof memo);
	cout << (f(0, 0, 1) - 1 + MOD) % MOD << endl;
}








