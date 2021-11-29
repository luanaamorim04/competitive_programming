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
#define P (1e4)
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

long double resp, a, b, c, d, l1, l2, r1, r2, v, q;

int pode(long double q)
{
	return !(q >= 2*min(l1, l2) || q <= 0);
}

long double volume(long double q)
{
	return q*(l1-(2*q))*(l2-(2*q));
}

int main()
{_
	while (cin >> l1 >> l2 && l1)
	{
		a = 12;
		b = -4*(l1+l2);
		c = l1*l2;
		d = (b*b) - (4*a*c);

		r1 = (-b + sqrt(d)) / (2*a);
		r2 = (-b - sqrt(d)) / (2*a);

		if (!pode(r1)) q = r2;
		if (!pode(r2)) q = r1;
		if (pode(r1) && pode(r2)) q = (volume(r1) > volume(r2) ? r1 : r2);

		cout << fixed << setprecision(4) << q << ' ' << volume(q) << endl;
	}
}





