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
#define MAX (int) (1e6 + 5)
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

int vis[MAX], n, k, resp;

int main()
{_
	cin >> n;
	while (n--)
	{
		cin >> k;
		for (int i = 1; i*i <= k; i++)
		{
			if (k % i == 0)
			{
				if (vis[i]) resp = max(resp, i);
				if (vis[k/i]) resp = max(resp, k/i);
				vis[i] = vis[k/i] = 1;
			}
		}
	}

	cout << resp << endl;
}
