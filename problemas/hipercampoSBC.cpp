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

int n, a, b, resp, memo[MAX];
tvector v[MAX], l, r;

int cmp(tvector a, tvector b)
{
	return a.y > b.y;
}

int pode(int last, int now)
{
	tvector a1 = (r-v[last]);
	tvector a2 = (v[now]-v[last]);
	tvector a3 = (l-v[last]);
	return ((a2^a1) > 0 && (a3^a2) > 0);
}

int f(int idx)
{
	int ans = 0;
	if (~memo[idx]) return memo[idx];
	for (int i = idx; i < n; i++)
		if (pode(idx-1, i)) ans = max(ans, f(i + 1) + 1);
	return memo[idx] = ans;
}

int main()
{_
	cin >> n >> a >> b;
	l = {a, 0};
	r = {b, 0};
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v[i] = {a, b};
	}

	sort(v, v+n, cmp);
	memset(memo, -1, sizeof memo);
	for (int i = 0; i < n; i++)
		resp = max(resp, f(i+1));
	cout << resp + 1 << endl;
}		












