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

ll n, arr[MAX], psa[MAX], k;

int bb(ll x)
{
	int ini = 1, meio, fim = n;
	while (ini <= fim)
	{
		meio = ini + ((fim-ini)>>1);
		if (psa[meio] == x) return 1;
		else if (psa[meio] > x) fim = meio - 1;
		else ini = meio + 1;
	}	
	return 0;
}

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		psa[i] = psa[i-1] + arr[i];
	}
	
 	if (psa[n]&1)
	{
		cout << "N" << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++)
		k += bb(psa[i]+(psa[n]>>1));

	cout << (k >= 2 ? "S" : "N") << endl;
}









