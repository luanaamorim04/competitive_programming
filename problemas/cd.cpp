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

ll n, arr[22], k, soma, resp, group;

int main()
{_
	while (cin >> n >> k)
	{
		for (int i = 0; i < k; i++) cin >> arr[i];
		resp = group = 0;
		for (int i = 0; i < (1<<k); i++)
		{
			soma = 0;
			for (int j = 0; j < k; j++)
				if (i&(1<<j)) soma += arr[j];

			if (soma <= n && soma >= resp)
			{
				if (soma > resp || __builtin_popcount(i) > __builtin_popcount(group))
				{
					resp = soma;
					group = i;
				}
			}
		}

		for (int i = 0; i < k; i++)
			if (group&(1<<i)) cout << arr[i] << ' ';
		cout << "sum:" << resp << endl;
	}
}



