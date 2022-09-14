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

int n, l, r, q, m, arr[MAX];
vector<int> freq[MAX];

int main()
{_
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		freq[arr[i]].push_back(i);
	}

	cin >> q;
	while (q--)
	{
		cin >> l >> r;
		int cnt = 50, a, ok = 0;
		while (cnt--)
		{
			int idx = l + (rand() % (r-l+1));
			int qtd = upper_bound(all(freq[arr[idx]]), r) - lower_bound(all(freq[arr[idx]]), l);
			// dbug(idx);
			// dbug(qtd);
			if (qtd*3 >= 2*(r-l+1))
			{
				ok = 2;
				cout << "YES" << endl;
				break;
			}
			else if (qtd*3 >= (r-l+1))
			{
				if (ok == 0) ok = 1, a = arr[idx];
				else if (arr[idx] != a) 
				{
					ok = 2;
					cout << "YES" << endl;
					break;
				}
			}
		}

		if (ok != 2)
			cout << "NO" << endl;
	}
}








