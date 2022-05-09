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

int n, m, arr[MAX], pos[MAX], k, i1;

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++) arr[i] = i, pos[i] = i;
	while (m--)
	{
		cin >> k;
		if (pos[k] < n)
		{
			i1 = pos[k];
			swap(pos[k], pos[arr[i1+1]]);
			swap(arr[i1], arr[i1+1]);
		}
		else
		{
			i1 = pos[k];
			swap(pos[k], pos[arr[i1-1]]);
			swap(arr[i1], arr[i1-1]);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}
