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
	long double x, y;
	tvector operator-(tvector q) const{
		return {x-q.x, y-q.y};
	}
	tvector operator+(tvector q) const{
		return {x+q.x, y+q.y};
	}
	tvector operator*(long double k) const{
		return {x*k, y*k};
	}
	tvector operator/(long double k) const{
		return {x/k, y/k};
	}
	long double operator^(tvector q) const{
		return hypot(x-q.x, y-q.y);
	}
	int operator==(tvector q) const{
		return (q.x==x && q.y==y);
	}
};

tvector a1, a2, resp;
long double r1, r2;

int main()
{_
	cin >> a1.x >> a1.y >> r1;
	cin >> a2.x >> a2.y >> r2;
	if (a1 == a2) 
	{
		cout << fixed << setprecision(11) << a1.x << ' ' << a1.y << endl;
		return 0;
	}
	if (r1 > r2) 
	{
		swap(r1, r2);
		swap(a1, a2);
	}

	resp = a1 + (((a2-a1)/(a2^a1))*r1);
	cout << fixed << setprecision(11) << resp.x << ' ' << resp.y << endl;
}	













