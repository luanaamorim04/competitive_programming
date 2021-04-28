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

int n;
ll resp, morre;

int main()
{_
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		morre = (i-1)*(i-2)<<2;
		resp = ((i*i)*((i*i) - 1)>>1) - morre;
		cout << resp << endl;
	}
}



