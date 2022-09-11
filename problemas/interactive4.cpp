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

int n, achar0, a, b, tot;
string s;

int query(string s)
{
	cout << "? " << s << endl;
	int x;
	cin >> x;
	return x;
}

void answer(int a, int b)
{
	cout << "! " << a << ' ' << b << endl;
}

int solve(int l, int r)
{
	// cout << l << '-' << r << ": " << tot << endl; 
	if (l==r) return l;
	int mid = (l+r)>>1;
	int tam = r-mid; //tamanho direita
	string s0, s1;
	for (int i = 1; i <= n; i++)
		s0 += '0'; 
	for (int i = 1; i <= n; i++)
		s1 += '0' + !(i >= l && i <= mid); 

	int q0 = tot;
	int q1 = query(s1);

	int qe = (q0+q1-l+1-n+mid)>>1;

	if ((!achar0 && qe) || (achar0 && qe != (mid-l+1))) return solve(l, mid);
	else return solve(mid+1, r);
}

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++) s += '0';

	tot = query(s);
	s[0] = '1';
	int r2 = query(s);

	achar0 = (tot > r2);
	int a = 1, b = solve(1, n);
	if (achar0) swap(a, b);
	answer(a, b); 
}















