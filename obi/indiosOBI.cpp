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

int n, m, f[MAX], pos[MAX], dir[MAX], resp;
vector<par> v;

int posicao_final(int ini, int tempo)
{
	if (~dir[ini]) return (pos[ini]+tempo) % n;
	else return (pos[ini]-tempo+n) % n;
}

int valido(int tempo)
{
	int r = 1;
	for (int i = 0; i < m; i++) f[posicao_final(i, tempo)]++;

	for (int i = 0; i < m; i++) r &= f[pos[i]], f[pos[i]] = 0;

	return r;
}

int tempo(int ini, int fim, int dir)
{
	if (dir == -1) swap(ini, fim);
	
	if (ini>fim) return (n-ini)+fim;
	return fim-ini;
}

int main()
{_
	cin >> n >> m;
	resp = n;
	for (int i = 0; i < m; i++)
	{
		cin >> pos[i] >> dir[i];
		v.push_back({--pos[i], dir[i]});
		if (i==0) v.pop_back();
	}

	for (auto[p, d] : v)
		if (valido(tempo(pos[0], p, dir[0]))) resp = min(resp, tempo(pos[0], p, dir[0]));

	cout << resp << endl;
}







