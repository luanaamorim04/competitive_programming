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
#define MAX (int) (2e6 + 5)
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

ll n, m, l, r, k, resp, tmp, arr[MAX];

int main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> l >> r >> k;
		arr[l] += k;
		arr[r+1] -= k;
	}

	resp = -INF;
	for (int i = 1; i <= n; i++)
	{
		arr[i] += arr[i-1];
		tmp += arr[i];
		resp = max(resp, tmp);
		if (tmp<0) tmp = 0;
	}
	cout << resp << endl;
}












