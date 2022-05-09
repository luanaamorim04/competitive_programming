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

ll t, n, idx;
ll psa[MAX];

int f(int x)
{
	return psa[x] >= n;
}

int main()
{_
	cin >> t;
	for (int i = 1; i < MAX; i+=2)
	{
		++idx;
		psa[idx] = psa[idx-1]+i;
	}

	while (t--)
	{
		cin >> n;
		int ok = 0;
		int ini = 1, meio, fim = (MAX>>1) - 2;
		while (ini <= fim)
		{
			meio = (ini+fim)>>1;
			if (f(meio)) fim = meio - 1;
			else ini = meio + 1;
		}
		
		ll x = psa[fim];
		for (int i = 1; i <= fim+1; i++)
			if (x + i == n)
			{
				cout << i << ' ' << fim+1 << endl;
				ok = 1;
				break;
			}

		if (ok) continue;
		ll soma = fim;
		for (int i = fim+1; i>= 1; i--)
		{
			soma++;
			if (x + soma == n)
			{
				cout << fim+1 << ' ' << i << endl;
				break;
			}
		}
	}
}












