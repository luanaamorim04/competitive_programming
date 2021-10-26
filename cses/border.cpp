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
#define BASE 37
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

string s;
ll suff[MAX], pref[MAX], b[MAX];
vector<int> ans;

int main()
{_
	cin >> s;
	b[0] = 1;
	for (int i = 1; i < MAX; i++)
		b[i] = (b[i-1]*BASE) % MOD; 

	pref[0] = (b[sz(s)-1]*s[0]) % MOD;
	for (int i = 1; i < sz(s); i++)
		pref[i] = (pref[i-1] + (b[sz(s)-(i+1)]*s[i])) % MOD;
	
	suff[sz(s)-1] = s[sz(s)-1];
	for (int i = sz(s)-2; i; i--)
		suff[i] = (suff[i+1] + (b[sz(s)-(i+1)]*s[i])) % MOD;

	for (int i = 0; i < sz(s); i++)
	{
		int tam = sz(s) - (i+1);
		if (pref[i] == ((suff[sz(s)-(i+1)]*b[tam])%MOD)) ans.push_back(i+1);
	}

	for (int i : ans) cout << i << ' ';

	cout << endl;
}












