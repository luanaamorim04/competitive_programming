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
#define MAX (int) (3e6 + 5)
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
#define int long long

using namespace std;

int n, m, l, r, val[MAX], qtd[MAX], val2[MAX], tira[MAX], tira2[MAX], qtd2[MAX];
vector<tuple<int, int, int> > a;

int32_t main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> l >> r;
		a.push_back({l, r, i&1});
	}

	sort(all(a));
	for (auto[l, r, flag] : a)
	{
		if (flag)
		{
			tira[r+1] += (r-l+1);
			qtd[l]++;
			qtd[r+1]--;
		}
		else
		{
			tira2[r+1] += (r-l+1);
			qtd2[l]++;
			qtd2[r+1]--;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		qtd[i] += qtd[i-1];
		val[i] = val[i-1] + qtd[i] - tira[i];
		qtd2[i] += qtd2[i-1];
		val2[i] = val2[i-1] + qtd2[i] - tira2[i];

		if (val[i]-val2[i]<0) 
		{
			cout << "UOY SI SAMTSIRHC ROF TNAW I LLA" << endl;
			return 0;
		}
	}

	cout << "ALL I WANT FOR CHRISTMAS IS YOU" << endl;
	return 0;
}





