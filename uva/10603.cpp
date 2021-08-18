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

struct vertice
{
	int d, a, b, c;
	int operator>(vertice q) const{
		return d>q.d;
	}
};

int a, b, c, D, t, dist[201][201][201];
priority_queue<vertice, vector<vertice>, greater<vertice> > fila;
vector<par> resp;

void f(int a, int b, int c, int d, int e, int f, int k)
{
	if (dist[a][b][c] == -1) dist[a][b][c] = INF;
	if (dist[d][e][f] == -1) dist[d][e][f] = INF;
	if (dist[a][b][c] > dist[d][e][f] + k)
	{
		dist[a][b][c] = dist[d][e][f] + k;
		fila.push({dist[a][b][c], a, b, c});
	}
}

void dijkstra()
{
	resp.clear();
	memset(dist, -1, sizeof dist);
	fila.push({0, 0, 0, c});
	dist[0][0][c] = 0;
	while (!fila.empty())
	{
		auto[d, a1, a2, a3] = fila.top(); fila.pop();
		if (d != dist[a1][a2][a3]) continue;
		int x = 0;
		if (a1 <= D) x = a1;
		if (a2 <= D) x = max(x, a2);
		if (a3 <= D) x = max(x, a3);
		resp.push_back({-x, d});

		int p = min(a1, b-a2); // 1 - 2
		f(a1-p, a2+p, a3, a1, a2, a3, p);
		p = min(a1, c-a3); // 1 - 3
		f(a1-p, a2, a3+p, a1, a2, a3, p);
		p = min(a2, a-a1); // 2 - 1
		f(a1+p, a2-p, a3, a1, a2, a3, p);
		p = min(a3, a-a1); // 3 - 1
		f(a1+p, a2, a3-p, a1, a2, a3, p);
		p = min(a2, c-a3); // 2 - 3
		f(a1, a2-p, a3+p, a1, a2, a3, p);
		p = min(a3, b-a2); // 3 - 2
		f(a1, a2+p, a3-p, a1, a2, a3, p);
	}	
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c >> D;
		dijkstra();
		sort(all(resp));
		cout << resp[0].second << ' ' << -resp[0].first << endl;
	}
}






