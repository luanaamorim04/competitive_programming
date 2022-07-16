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

int n, m, q, a, b, pai[MAX], tam[MAX], tempo[MAX], t;

int find(int x)
{
	if (x==pai[x]) return x;
	return find(pai[x]);
}

void join(int a, int b)
{
	++t;
	int A = find(a), B = find(b);
	if (A==B) return;
	if (tam[A] > tam[B]) swap(A, B);
	pai[A] = B;
	tam[B] += tam[A];
	tempo[A] = t;
}

int solve(int a, int b)
{
	int resp = 0;
	if (find(a) != find(b)) return -1;
	while (a != b)
	{
		resp = max(resp, min(tempo[a], tempo[b]));
		if (tempo[a] < tempo[b]) a = pai[a];
		else b = pai[b];
	}

	return resp;
}

int main()
{_
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		pai[i] = i, tam[i] = 1, tempo[i] = INF;

	while (m--)
	{
		cin >> a >> b;
		join(a, b);
	}
	while (q--)
	{
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
}








