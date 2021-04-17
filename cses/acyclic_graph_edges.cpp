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
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
int n, m, a, b, passou[1<<20];
vector<int> grafo[1<<20];
map<par, int> mapa;
vector<par> v;

int main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
		v.push_back({a, b});
	}
 
	for (int u = 1; u <= n; u++)
		for (int v : grafo[u])
			if (mapa.find({v, u}) == mapa.end()) mapa[{u, v}] = 1;

	//cout << mapa[{4, 5}] << ' ' << mapa[{5, 4}] << endl;

 
 	for (auto [a, b] : v)
 	{
 		if (mapa[{a, b}]) cout << a << ' ' << b << endl;
 		else cout << b << ' ' << a << endl;
 	}
 
}
 