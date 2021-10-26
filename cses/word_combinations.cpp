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
#define MAX (int) (1e6 + 7)
#define MOD 1000000007
#define A 37
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
 
ll a1[MAX], h1[MAX], s1[MAX], dp[MAX], p1;
int n, arr[MAX], tam, c;
string s, p;
 
int main()
{_
	cin >> s >> n;
	tam = sz(s);
	a1[0] = 1;
	for (int i = 1; i < MAX; i++)
		a1[i] = (a1[i-1]*A) % MOD;
 
	s1[0] = (a1[tam-1]*s[0]) % MOD;
	for (int i = 1; i < tam; i++)
		s1[i] = (s1[i-1] + (s[i]*a1[tam - (i+1)])) % MOD;
 
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		arr[i] = sz(p);
		h1[i] = (a1[arr[i]-1]*p[0]) % MOD;

		for (int j = 1; j < arr[i]; j++)
			h1[i] = (h1[i] + (p[j]*a1[arr[i] - (j+1)])) % MOD;
	}
 
	dp[tam] = 1;
	for (int i = tam-1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			c = (tam-i)-arr[j];
			if (c < 0) continue;
			p1 = (s1[i + (arr[j]-1)] - (i?s1[i-1]:0) + MOD) % MOD;
 
			if (p1 == ((h1[j]*a1[c])%MOD)) dp[i] += dp[i+arr[j]];
		}

		dp[i] %= MOD;
	}
 
	cout << dp[0] << endl;
}
 
 
 
 
 
 
 
 
 
 
 
 