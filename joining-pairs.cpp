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

vector<par> v, h, arr;
vector<tuple<int, int, int, int> > d;
int a1, a2, b1, b2, n, m, q, baixo, cima, resp;

int main()
{_
	cin >> n >> m >> q;
	while (q--)
	{
		cin >> a1 >> b1 >> a2 >> b2;
		if (a1 > a2) swap(a1, a2);
		if (b1 > b2) swap(b1, b2);

		if (a1 == 0 && a2 == n)
		{	
			if (b1 == 0 && b2 == m) d.push_back({a1, b1, a2, b2});
			else h.push_back({b1, b2});
		}
		else if (b1 == 0 && b2 == m)
		{
			if (a1 == 0 && a2 == n) d.push_back({a1, b1, a2, b2});
			else v.push_back({a1, a2});
		}
	}

	if (sz(v) && sz(h)) 
	{
		cout << "N" << endl;
		return 0;
	}

	for (auto[a, b, c, d] : d)
	{
		if (sz(v)) arr.push_back({a, c});
		else arr.push_back({b, d});
	}

	for (auto[a, b] : v) 
		arr.push_back({a, b});

	for (auto[a, b] : h) 
		arr.push_back({a, b});

	sort(all(arr));
	resp = 1;
	for (auto[a, b] : arr)
	{
		baixo = a;
		cima = max(cima, b);
		resp &= (baixo < cima);
	}

	cout << (resp ? "Y" : "N") << endl;
}












