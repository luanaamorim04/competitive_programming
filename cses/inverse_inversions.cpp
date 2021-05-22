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
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, k, ans, soma, atual, l, r;

int main()
{_
	cin >> n >> k;
	l = 1, r = n;

	while (l <= r)
	{
		atual = r-l;
		if (soma + atual <= k) 
		{
			soma += atual;
			cout << r << ' ';
			r--;
		}
		else
		{
			cout << l << ' ';
			l++;
		}
	}
	cout << endl;
}









