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
#define INF (1e16)
#define MAX (int) (3e5 + 5)
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

ll t, n, k, arr[MAX], esq[MAX], dir[MAX], z;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		vector<int> pos;
		for (int i = 1; i <= n; i++) arr[i] = INF;
		for (int i = 0; i < k; i++)
		{
			cin >> z;
			pos.push_back(z);
		}

		for (int i : pos) cin >> arr[i];

		esq[0] = dir[n+1] = INF;
		for (int i = 1; i <= n; i++)
			esq[i] = min(esq[i-1]+1, arr[i]);
		for (int i = n; i >= 1; i--)
			dir[i] = min(dir[i+1]+1, arr[i]);

		for (int i = 1; i <= n; i++)
			cout << min(esq[i], dir[i]) << ' ';
		cout << endl;
	}
}
















