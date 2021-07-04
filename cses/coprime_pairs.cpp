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
#define MAX (int) (1e6) 
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
 
bitset<MAX + 10> composto;
ll d[MAX], n, k, resp;
set<int> conj;
vector<int> p;
 
void crivo()
{
	composto[1] = 1;
	for (int i = 2; i*i <= MAX; i++)
	{
		if (!composto[i])
		{
			for (int j = i; j*i <= MAX; j++)
				composto[j*i] = 1;
		}
	}
}
 
void f(ll primo, ll add, int idx)
{
	resp += ((d[primo]*(d[primo]-1))*add);
 
	for (int i = idx; i < p.size(); i++)
	{
		if (primo*p[i] > MAX) break;
	 	f(primo*p[i], -1*add, i+1);
	}
}
 
void decomp(int x)
{
	for (int i = 1; i*i <= x; i++)
	{
		if (x % i == 0)
		{
			if (!composto[x/i]) conj.insert(x/i);
			if (!composto[i]) conj.insert(i);
			d[i]++;
			if (x/i != i) d[x/i]++;
		}
	}
}
 
int main()
{_
	crivo();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		decomp(k);
	}
 
	for (int x : conj) p.push_back(x);
 
	d[1] = 0;
	f(1, -1, 0);
	cout << ((n*(n-1))>>1) - (resp>>1) << endl;
}