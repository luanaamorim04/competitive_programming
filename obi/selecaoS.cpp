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

ll n, k, b, c, d, arr1[MAX], arr2[MAX];

int f(int x)
{
	ll r = 0, resp = 0;
	int ptr = n-1;
	for (int i = 0; i < n; i++)
	{
		while (ptr>=0 && arr1[i]+arr2[ptr]>x) r++, ptr--;
		resp += (n-r);
	}

	return resp>=k;
}

int main()
{_
	cin >> n >> k;
	cin >> arr1[0] >> b >> c >> d;
	for (int i = 1; i < n; i++)
		arr1[i] = (b + (c*arr1[i-1])) % d;
	cin >> arr2[0] >> b >> c >> d;
	for (int i = 1; i < n; i++)
		arr2[i] = (b + (c*arr2[i-1])) % d;

	sort(arr1, arr1+n);
	sort(arr2, arr2+n);

	int ini = 0, meio, fim = MAX;
	while (ini <= fim)
	{
		meio = ini + ((fim-ini)>>1);
		if (f(meio)) fim = meio - 1;
		else ini = meio + 1;
	}
	
	// for (int i = 0; i < n; i++)
	// 	cout << arr1[i] << ' ' << arr2[i] << endl;
	cout << fim + 1 << endl;
}












