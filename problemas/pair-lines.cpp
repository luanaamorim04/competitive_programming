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

struct tvector
{
	ll x, y;

	tvector operator-(tvector a) const{
		return {(x-a.x), (y-a.y)};
	}

	ll operator^(tvector a) const{
		return (x*a.y)-(y*a.x);
	}	
};

int n, passou[MAX], resp;
tvector arr[MAX];

void reta1(int a, int b)
{
	for (int i = 0; i < n; i++)
	{
		if (((arr[a]-arr[i])^(arr[b]-arr[i])) == 0)
			passou[i] = 1;
	}
}

int reta2()
{
	tvector a, b;
	int ok = 0;
	for (int i = 0; i < n; i++)
	{
		if (passou[i]) continue;
		if (!ok) a = arr[i], ok = 1;
		else b = arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (passou[i]) continue;
		if ((a-arr[i])^(b-arr[i])) return 0;
	}

	return 1;
}

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;

	if (n <= 4) 
	{
		cout << "YES" << endl;
		return 0;
	} 

	reta1(0, 1);
	resp |= reta2();
	memset(passou, 0, sizeof passou);
	reta1(1, 2);
	resp |= reta2();
	memset(passou, 0, sizeof passou);
	reta1(0, 2);
	resp |= reta2();
	memset(passou, 0, sizeof passou);

	cout << (resp?"YES":"NO") << endl;
}
















