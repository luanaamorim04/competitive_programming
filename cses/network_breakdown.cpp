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
#define MAX (int) (2e5 + 10)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, k, a, b, comp, pai[MAX];
map<par, int> pode;
par arr[MAX], tira[MAX];
vector<int> resp;
set<int> s;

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

int join(int a, int b)
{
	a = find(a), b = find(b);
	pai[a] = pai[b];
	return a != b;
}

int main()
{_
	cin >> n >> m >> k;
	comp = n;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (a > b) swap(a, b);
		arr[i] = {a, b};
	}

	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		if (a > b) swap(a, b);
		tira[i] = {a, b};
		pode[{a, b}] = -1;
	}

	for (int i = 1; i <= n; i++) pai[i] = i;

	for (int i = 0; i < m; i++)
	{
		auto [a, b] = arr[i];
		if (pode[{a, b}] != -1) 
		{
			comp -= join(a, b);
		}
	}

	resp.push_back(comp);

	for (int i = k-1; i > 0; i--)
	{
		auto [a, b] = tira[i];
		comp -= join(a, b);
		resp.push_back(comp);
	}

	for (int i = resp.size() - 1; i >= 0; i--)
		cout << resp[i] << ' ';
	cout << endl;

}





