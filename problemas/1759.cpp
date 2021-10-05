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

unsigned ll resp, soma, idx, b, arr[MAX];
string s, v;

int main()
{_
	cin >> s;
	b = 1;
	for (int i = 0; i < sz(s); i++)
	{
		arr[i] = ((s[i]-'A')*(i+1)) % MOD;
		soma = (soma + arr[i]) % MOD;
	}

	for (int i = sz(s)-1; i >= 0; i--)
	{
		resp = (resp + (soma*b)) % MOD;
		soma = (soma - arr[i] + MOD) % MOD;
		b = (b * 26) % MOD;
	}

	while (resp)
	{
		v.push_back((resp%26)+'A');
		resp /= 26;
	}

	reverse(all(v));
	if (!sz(v)) cout << 'A' << endl;
	else cout << v << endl;
}




























