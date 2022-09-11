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
#define MAX (int) (2e3 + 5)
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

int n, m[MAX][MAX];
vector<int> v;

int query(int l, int r)
{
	cout << "? " << l << ' ' << r << endl;
	int soma;
	cin >> soma;
	return soma;
}

void answer(vector<int> v)
{
	cout << "! ";
	for (int x : v) cout << x << ' ';
	cout << endl;
}

int main()
{_
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		m[1][i] = query(1, i);
	}

	v.push_back(m[1][n] - query(2, n));
	v.push_back(m[1][2] - v[0]);

	for (int i = 3; i <= n; i++)
		v.push_back(m[1][i]-m[1][i-1]);

	answer(v);
}










