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

int n, k;
ll pos[MAX], qnt[MAX];

int f(int t)
{
	priority_queue<par, vector<par>, greater<par> > fila;
	for (int i = 0; i < k; i++) fila.push({})
	return 1;
}

int main()
{_
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> pos[i];
	for (int i = 1; i <= n; i++)
		cin >> qnt[i];

	int ini = 1, meio, fim = INF;
	while (ini <= fim)
	{
		meio = ini + ((fim-ini)>>1);
		if (f(meio)) ini = meio + 1;
		else fim = meio - 1;
	}

	cout << ini - 1 << endl;
}











