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
#define MAX (int) (2e6 + 5)
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

int n, q, op, a, b;
ll arr[MAX], soma[MAX];
vector<int> primos;
void crivo()
{
	for (int i = 2; i < MAX; i++)
	{
		if (!p[i])
		{
			primos.push_back(i);
			p[i] = i;
			for (int j = i*i; j < n; j+=i)
				p[j] = i;
		}
	}
}

int main()
{_
	cin >> n >> q;
	crivo();
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		int tmp = i, idx = 0;
		while (tmp > 1)
		{

		}
		soma[]
	}

	while (q--)
	{

	}
}






