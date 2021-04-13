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
#define MAX (int) (2e6 + 5)
#define MOD 1000000007
#define ADD ((int) 1e6 + 1)
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, resp, a1, a2, b1, b2, idx, ft[MAX];
pair<int, par> arr[1<<20];
set<int> pontos;

int query(int idx)
{
	int ans = 0;
	while (idx > 0)
	{
		ans += ft[idx];
		idx -= lsb(idx);
	}
	return ans;
}

void update(int idx, int val)
{
	while (idx < MAX)
	{
		ft[idx] += val;
		idx += lsb(idx);
	}
}

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a1 >> b1 >> a2 >> b2;
		if (a1 == a2)
		{
			arr[idx++] = {a1 + ADD, {b1 + ADD, b2 + ADD}};
		}
		else
		{
			arr[idx++] = {a1 + ADD, {-1, b1 + ADD}};
			arr[idx++] = {a2 + ADD, {INF, b1 + ADD}};
		}
	}

	sort(arr, arr+idx);

	for (int i = 0; i < idx; i++)
	{
		auto line = arr[i];
		if (line.second.first == -1)
		{
			update(line.second.second, 1);
		}
		else if (line.second.first == INF)
		{
			update(line.second.second, -1);
		}
		else
		{
			resp += query(line.second.second) - query(line.second.first - 1);
		}
	}

	cout << resp << endl;
}






