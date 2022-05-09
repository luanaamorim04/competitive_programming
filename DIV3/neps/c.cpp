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

ll resp, n, a[MAX], b[MAX], arr[MAX], tmp, soma;

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		soma += a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		arr[i] = b[i] - a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		tmp += arr[i];
		if (tmp < 0) tmp = 0;
		resp = max(resp, tmp);
	}

	cout << soma + resp << endl;
}







