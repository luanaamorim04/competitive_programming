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
#define dbug(x) cout << (#x) << " -> " << x << endl
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

int n, m, q, a1, b1, a2, b2;

int borda(int x, int y)
{
	return (x==0||x==n||y==0||y==m);
}

int val(int x, int y)
{
	if (x==0) return y;
	if (y==m) return m+x;
	if (x==n) return (m+n)+(m-y);
	return (m+m+n)+(n-x);
}

vector<pair<int, int> > v;
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{_
	cin >> n >> m >> q;
	while (q--)
	{
		cin >> a1 >> b1 >> a2 >> b2;
		if (borda(a1, b1) && borda(a2, b2))
		{
			int a = val(a1, b1);
			int b = val(a2, b2);
			if (a>b) swap(a, b);
			v.push_back({a, b});
			// cout << a << ' ' << b << endl;
		}
	}

	sort(all(v));
	for (auto[a, b] : v)
	{
		while (!pq.empty() && pq.top() < a) pq.pop();
		if (!pq.empty() && pq.top() <= b) 
		{
			cout << "N" << endl;
			return 0;
		}
		pq.push(b);
	}

	cout << "Y" << endl;
}
















