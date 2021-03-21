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

int n, k, resp;
par films[1<<20];
multiset<int> s;
multiset<int>::iterator it;

/*
10 5

57 69 1
35 72 2
53 78 3
77 79 2
49 87 4
80 90 2
75 94 1
46 95 5
64 95 
22 99
*/

int main()
{_
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> films[i].second >> films[i].first;

	while (k--) s.insert(0);

	sort(films, films+n);

	for (int i = 0; i < n; i++)
	{
		it = s.lower_bound(-films[i].second);
		if (it != s.end())
		{
			s.erase(it);
			s.insert(-films[i].first);
			++resp;
		}
	}
	cout << resp << endl;






}
