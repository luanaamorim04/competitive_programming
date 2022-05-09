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

int t, qnt1, qnt2, a1, a2;
string s;

int f(int idx, int g1, int g2)
{
	if (idx > 10) return 10;

	g2 += (s[idx-1] == '1' && !(idx&1));
	g1 += (s[idx-1] == '1' && (idx&1));

	if ((g1 > ((10+(idx&1)-idx)>>1) + g2)) return idx;
	if ((g2 > ((10-idx)>>1) + g1)) return idx;

	if (s[idx-1] == '?' && (idx&1))
	{
		if (g1+1 > ((11-idx)>>1) + g2) return idx;
		return min(f(idx+1, g1+1, g2), f(idx+1, g1, g2));
	} 
	if (s[idx-1] == '?' && !(idx&1)) 
	{
		if (g2+1 > ((10-idx)>>1) + g1) return idx;
		return min(f(idx+1, g1, g2), f(idx+1, g1, g2+1));
	}

	return f(idx+1, g1, g2);
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> s;
		cout << f(1, 0, 0) << endl;
	}
}








