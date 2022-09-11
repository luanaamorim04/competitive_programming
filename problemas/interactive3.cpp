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

int n, m, c, arr[MAX], mid1, mid2;

int acabou(int l, int r)
{
	if (arr[l] == -1) return 0;
	for (int i = l+1; i <= r; i++)
		if (arr[i] < arr[i-1] || arr[i] == -1) return 0;
	return 1;
}

int query()
{
	int a;
	cin >> a;
	return a;
}

void answer(int i)
{
	cout << i << endl;
}

void update1(int l, int r, int k)
{
	for (int i = l; i <= r; i++)
	{
		if (arr[i] > k || arr[i] == -1) 
		{
			answer(i);
			arr[i] = k;
			return;
		}
	}
}

void update2(int l, int r, int k)
{
	for (int i = r; i >= l; i--)
	{
		if (arr[i] < k || arr[i] == -1) 
		{
			answer(i);
			arr[i] = k;
			return;
		}
	}
}

int main()
{_
	cin >> n >> m >> c;
	for (int i = 0; i <= n+1; i++) arr[i] = -1;
	int mid1 = 1, mid2 = n;
	while (!acabou(1, n))
	{
		int k = query();
		if (k <= (c>>1)) update1(1, mid1, k);
		else update2(mid2, n, k);

		while (acabou(1, mid1) && mid1 <= n) mid1++;
		while (acabou(mid2, n) && mid2 >= 1) mid2--;
	}

}






