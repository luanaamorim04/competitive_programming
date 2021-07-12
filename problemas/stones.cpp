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

int n, k, arr[101], memo[MAX];

int f(int k)
{
	if (k == 0) return 0;
	if (~memo[k]) return memo[k];
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (k >= arr[i]) ans |= (!f(k - arr[i]));

	//cout << k << ' ' <<  ans << endl;
	return memo[k] = ans;
}

int main()
{_
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(memo, -1, sizeof memo);
	cout << (f(k) ? "First" : "Second") << endl;
}
