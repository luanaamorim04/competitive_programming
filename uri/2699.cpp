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
#define ll long long
#define INF (1e9)
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s;
int dig[1001], memo[1001][2][1001], mod;

int pot(int x, int d)
{
	int ans = 1, a = 10;
	while (x)
	{
		if (x&1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		x>>= 1;
	} 
	return (ans*d) % mod;
}

int f(int idx, int null, int resto)
{
	if (idx == -1) return !resto && !null;
	int &ans = memo[idx][null][resto];
	if (~ans) return ans;
	ans = 0;

	if (~dig[idx])
		return ans = f(idx - 1, (null && !dig[idx]), (resto + pot(idx, dig[idx])) % mod);

	for (int d = null; d <= 9; d++)
	{
		ans |= f(idx - 1, (null && !d), (resto + pot(idx, d)) % mod);
		if (ans) 
		{
			dig[idx] = d;
			return ans;
		}
	}

	return ans;
}

int main()
{_
	cin >> s >> mod;

	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < s.size(); i++)
		dig[s.size()-i-1] = (s[i] != '?' ? s[i]-'0' : -1);

	int resp = f(s.size() - 1, 1, 0);

	if (!resp)
	{
		cout << '*' << endl;
		return 0;
	}

	for (int i = s.size() - 1; i >= 0; i--)
		cout << dig[i];

	cout << endl;
}


















