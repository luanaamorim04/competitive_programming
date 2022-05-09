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

int n, a, b, cor, ini;

int main()
{_
	cin >> n >> a >> b;
	ini = 1;
	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < a; y++)
		{
			cor = ini;
			for (int j = 0; j < n; j++)
			{
				for (int x = 0; x < b; x++)
					cout << (cor ? '.' : '#');
				cor ^= 1;
			}
			cout << endl;
		}

		ini ^= 1;
	}
}
