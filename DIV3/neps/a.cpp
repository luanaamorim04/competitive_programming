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

int n, q, m, x;
map<int, vector<int> > pos;

int bb(int x, int k)
{
	int ini = 0, meio, fim = sz(pos[x])-1;
	while (ini <= fim)
	{
		meio = (ini+fim)/2;
		if (pos[x][meio] > k) fim = meio - 1;
		else ini = meio + 1;
	}

	return (fim+1 == sz(pos[x]) ? -1 : fim + 1);
}

int main()
{_
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		pos[x].push_back(i);
	}

	while (q--)
	{
		cin >> m;
		int maxn = -1;
		int r = 1;
		for (int i = 0; i < m; i++)
		{
			cin >> x;
			if (bb(x, maxn) == -1) 
			{
				r = 0;
			}
			maxn = bb(x, maxn);
		}

		cout << (r ? 'S' : 'N') << endl;
	}
}












