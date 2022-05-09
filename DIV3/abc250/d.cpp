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
#define ll unsigned long long
#define INF (1e9)
#define MAX (int) (1e6 + 5)
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

ll resp, n, composto[MAX];
vector<ll> p;

void crivo()
{
	for (int i = 2; i*i < MAX; i++)
	{
		if (!composto[i])
		{
			for (int j = i*i; j < MAX; j += i)
				composto[j] = 1;
		}
	}

	for (int i = 2; i < MAX; i++) if (!composto[i]) p.push_back(i);
}

int main()
{_
	cin >> n;
	crivo();
	int i = 1, j = 0;
	ll num = 27;
	while (num*2 <= n && i+1 < p.size())
	{
		while (num*p[j+1] <= n && j+1 < i) ++j;
		while (num*p[j] > n) --j;
		resp += (j+1);

		++i;
		num = p[i]*p[i]*p[i];
	}

	cout << resp << endl;
}





