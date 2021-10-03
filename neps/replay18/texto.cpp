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
#define MAX 50
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

ll n, m, arr[MAX], resp, soma;
map<ll, ll> mapa;

int main()
{_
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	ll k = (n>>1);
	for (int i = 0; i < 1<<k; i++)
	{
		soma = 0;
		for (int j = 0; j < k; j++)
			if (i&(1<<j)) soma += arr[j];
		
		resp |= (soma==m);
		if (soma < m) mapa[soma] = 1;
	}

	for (int i = 0; i < 1<<(n-k); i++)
	{
		soma = 0;
		for (int j = k; j < n; j++)
			if (i&(1<<(j-k))) soma += arr[j];
		
		if (soma < m) resp |= (mapa.find(m-soma) != mapa.end());
	}

	cout << (resp ? "sim" : "nao") << endl;
}
















