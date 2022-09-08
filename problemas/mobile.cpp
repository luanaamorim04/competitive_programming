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
#define INF (2e9 + 5)
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
#define ERR 1e-9

using namespace std;

double l, n, a[MAX], b[MAX];

int check(double raio)
{
	double fim = 0;
	for (int i = 0; i < n; i++)
	{
		if (raio < b[i]) continue;
		double prox_fim = a[i] + (sqrt((raio*raio) - (b[i]*b[i])));
		double prox_ini = a[i] - (sqrt((raio*raio) - (b[i]*b[i])));
		if (prox_ini <= fim) fim = max(prox_fim, fim);
	}

	return (fim >= l);
}

int main()
{_
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	int cnt = 45;
	double meio, ini = 0, fim = INF;
	while (cnt--)
	{
		meio = (ini+fim)/2;
		if (check(meio)) fim = meio;
		else ini = meio;
	}

	cout << fixed << setprecision(6) << fim << endl;
}















