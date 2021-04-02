#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, arr[1<<10];
map<int, vector<par> > s;

int main()
{_
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			s[arr[i] + arr[j]].push_back({i, j});

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (par p : s[m - (arr[i]+arr[j])])
				if (p.first != j && p.first != i && p.second != i && p.second != j)
				{
					cout << i + 1 << ' ' << j + 1 << ' ' << p.first + 1 << ' ' << p.second + 1 << endl;
					return 0;
				}

	cout << "IMPOSSIBLE" << endl;
}
