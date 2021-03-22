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

ll n, soma, a, p[1<<20];
set<int> s1, s2;
set<int>::iterator it;

int main()
{_
	cin >> n;
	if ((n + 1) % 4 && n % 4)
	{
		cout << "NO" << endl;
		return 0;
	}	
	cout << "YES" << endl;

	soma = (n*(n+1))/4;
	for (int i = n; i >= 1; i--)
	{
		if (soma - i >= 0) soma -= i, s1.insert(i);
		else s2.insert(i);
	}

	cout << s1.size() << endl;
	for (it = s1.begin(); it != s1.end(); it++)
		cout << (*it) << ' ';
	cout << endl << s2.size() << endl;
	for (it = s2.begin(); it != s2.end(); it++)
		cout << (*it) << ' ';
	cout << endl;

	
















}
