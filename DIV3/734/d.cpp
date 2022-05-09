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

int t, n, m, k;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		// int resp = (k/2);
		// int resto = 2*(resp + (m>>1) - 1) / (m>>1);
		if (!k && (n&1)) cout << "NO" << endl;
		else if (!k) cout << "YES" << endl;
		else cout << ((n%k == 0 || m%k == 0) ? "YES" : "NO") << endl;
	}
}









