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
#define ll long long
#define INF (1e9)
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int x, n, a, b, z;
set<int> pos;
set<pair<int, par> > resp;

int main()
{_
	cin >> x >> n;
	pos.insert(0);
	pos.insert(x);
	resp.insert({x, {0, x}});
	for (int i = 0; i < n; i++)
	{
		cin >> z;
		auto it = pos.upper_bound(z);
		b = (*it);
		it--;
		a = (*it);
		pos.insert(z);
		resp.erase({b - a, {a, b}});
		resp.insert({b - z, {z, b}});
		resp.insert({z - a, {a, z}});
		cout << (*resp.rbegin()).first << ' ';
	}
	cout << endl;
}






















