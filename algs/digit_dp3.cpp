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

//saber quantos 7s aparecem de 0..n

/*
n = 213
dig[0] = 3;
dig[1] = 1;
dig[2] = 2;

*/

int maxn, dig[20], n;

int dcomp(int x)
{
	int idx = 0;
	while (x)
	{
		dig[idx++] = x%10;
		x /= 10;
	}
	return idx-1;
}

int f(int idx, int igual, int qnt)
{
	if (idx == -1) return qnt;

	int l = igual ? dig[idx] : 9, ans = 0;

	for (int d = 0; d <= l; d++)
	{
		ans += f(idx - 1, (igual && (d==l)), qnt + (d==7));
	}

	return ans;
}

int main()
{_
	cin >> n;
	int m = dcomp(n);
	cout << f(m, 1, 0) << endl;
}





