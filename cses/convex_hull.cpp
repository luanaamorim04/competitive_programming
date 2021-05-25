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
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct tvector
{
	ll x, y;

	ll operator^(tvector q) const{
		return (x*q.y) - (q.x*y);
	}

	tvector operator-(tvector q) const{
		return {x-q.x, y-q.y};
	}

	int operator<(tvector q) const{
		return (x != q.x ? x < q.x : y < q.y);
	}
};

int n;
tvector p[1<<20];
vector<tvector> upper, lower;

int main()
{_	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;

	sort(p, p+n);

	for (int i = 0; i < n; i++)
	{
		int sz = upper.size();
		while (sz > 1 && ((upper[sz-1]-upper[sz-2])^(p[i]-upper[sz-2])) > 0) upper.pop_back(), sz--;
		upper.push_back(p[i]);
	}	

	upper.pop_back();
	for (int i = n-1; i >= 0; i--)
	{
		int sz = lower.size();
		while (sz > 1 && ((lower[sz-1]-p[i])^(lower[sz-2]-p[i])) < 0) lower.pop_back(), sz--;
		lower.push_back(p[i]);
	}	
	lower.pop_back();	

	cout << lower.size() + upper.size() << endl;
 	for (auto[a, b] : upper)
		cout << a << ' ' << b << endl;
	for (auto[a, b] : lower)
		cout << a << ' ' << b << endl;
}




















