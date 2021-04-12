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
#define MAX (1<<10) + 10
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/*
	f(i, mask) = quantidade de maneiras de formar um quadrado n-i+1 por log2mask com peças 1x2 e 2x1
	resposta = f(1, 0);
	primeiro -> ter informações do andar abaixo. Se bit estiver setado, posição ocupada.
	segundo -> montar o andar de acordo com o as especificações e chamar f(i+1, mask) para 
	toda mask valida.

	f(n, mask) = 1;
	i > n = 0;
	
	mask | mask2 == 0;

*/

int n, m;
ll memo[MAX][MAX];


int e(int a, int mask)
{
	if (mask&a) return 0;
	int inv = -1;
	a |= (1<<n);
	mask |= (1<<n);
	for (int i = 0; i < n; i++)
	{
		if ((a&(1<<i)) || (mask&(1<<i)) || (inv != i-1)) inv = i;
		else if ((a&(1<<(i+1))) || (mask&(1<<(i+1)))) return 0;
	}
	return 1;
}

ll f(int andar, int mask)
{
	if (andar > m) return !mask;
	if (~memo[andar][mask]) return memo[andar][mask];
	ll ans = 0;
	for (int i = 0; i < (1<<n); i++)
		if (e(i, mask)) ans = (ans + f(andar+1, i)) % MOD;

	return memo[andar][mask] = ans;
}

int main()
{_
	cin >> n >> m;
	memset(memo, -1, sizeof memo);
	cout << f(1, 0) << endl;
}





















