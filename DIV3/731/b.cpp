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

int t, x;
string s;

int f(int i, int j, int idx)
{
	if (i == 0 && j == s.size()-1) return 1;
	if (i > 0 && s[i-1] == idx) return f(i-1, j, idx+1);
	if (j < s.size() && s[j+1] == idx) return f(i, j+1, idx+1);
	return 0;
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> s;
		x = -1;
		for (int i = 0; i < s.size(); i++) if (s[i] == 'a') x = i;
		cout << ((x != -1 && f(x, x, 'b')) ? "YES" : "NO") << endl;
	}
}
