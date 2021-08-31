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

ll n, m;

ll f(ll x)
{
	ll a1 = (4*n) - 4;
	ll an = a1 + (-8*(x-1));
	ll resp = ((a1 + an)*x)>>1;
	return resp;
}
			
int main()	
{_
	cin >> n >> m;
	ll ini = 1, meio, fim = n>>1;
	while (ini <= fim)
	{
		meio = ini + ((fim-ini)>>1);
		if (m > f(meio)) ini = meio + 1;
		else fim = meio - 1;
	}

	ll k = ini - 1;
	ll lado = (n-(k<<1));
	if (f(k) + lado >= m)
		cout << k+1 << ' ' << k + (m - f(k)) << endl;
	else if (f(k) + (2*lado) - 1 >= m)
		cout << k + 1 + (m - (f(k) + lado)) << ' ' << n-k << endl;
	else if (f(k) + (lado*3) - 2 >= m)
		cout << n-k << ' ' << n - (k + m - (f(k) + (2*lado) - 1)) << endl; 
	else
		cout << n-(k+m-(f(k) + (lado*3) - 2)) << ' ' << k+1 << endl;
}











