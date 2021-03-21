#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
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

int n, m, x, y;
multiset<int> s;
multiset<int>::iterator it;

int main()
{_
	cin >> n >> m;
	while (n--)
	{
		cin >> x;
		s.insert(-x);
	}

	while (m--)
	{
		cin >> x;
		it = s.lower_bound(-x);
		if (it == s.end()) 
		{
			cout << -1 << endl;
			continue;
		}
		cout << -(*it) << endl;
		s.erase(it);
	}

	return 0;
}
