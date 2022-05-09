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
#define MAXL 20

using namespace std;

int n, q, pai[MAX], h[MAX], up[MAXL][MAX], nivel[MAX], val[MAX], a, b;
vector<int> st[MAX], grafo;

int build_hld(int u, int p)
{
	pai[u] = p;
	nivel[u] = nivel[p] + 1;
	for (int v : grafo[u])
	{

	} 
}	

int main()
{_
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> val[i+1];

	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);

	}
}

















