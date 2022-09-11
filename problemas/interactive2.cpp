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

int n;
vector<int> v;

int query(int l, int r)
{
	cout << "? " << l << ' ' << r << endl;
	int a;
	cin >> a;
	return a;
}

void answer(vector<int> v)
{
	cout << "! ";
	for (int x : v) cout << x << ' ';
	cout << endl;
}

int main()
{
	cin >> n;
	int x = query(1, 2);
	int y = query(2, 3);
	int z = query(1, 3);

	int b = (y-z+x)>>1;
	int a = x-b;
	int c = y-b;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);

	for (int i = 4; i <= n; i++)
		v.push_back(query(1, i) - v[0]);

	answer(v);






}
