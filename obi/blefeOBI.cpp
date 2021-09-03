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

int n, m, a, b, ok;
set<int> s, v;

int main()
{_
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		cin >> a;
		s.insert(a);
	}

	for (int i = 0; i < m; i++) 
	{
		cin >> b;
		ok = (s.find(b) != s.end());
		if (!ok) for (int c : v) 
		{
			if (ok) break;
			ok |= (v.find(b - c) != v.end());
		}
		if (!ok)
		{
			cout << b << endl;
			return 0;
		}
		
		v.insert(b);
 	}

 	cout << "sim" << endl;
}			















