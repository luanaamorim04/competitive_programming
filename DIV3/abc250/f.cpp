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
#define INF (ll) (1LL<<62)
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
ll resp, area, atual;

struct tvector
{
	ll x, y;
	ll operator*(tvector q) const {
		return (x*q.y)-(q.x*y);
	}
	tvector operator-(tvector q) const{
		return {x-q.x, y-q.y};
	}
};

tvector arr[MAX];

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;

	for (int i = n; i < (n<<1); i++)
		arr[i] = arr[i-n];

	for (int i = 1; i < n-1; i++)
		area += abs((arr[i]-arr[0])*(arr[i+1]-arr[0]));

	resp = INF;
	for (int r = 2, l = 0; r < (n<<1); r++)
	{
		atual += (abs((arr[r]-arr[l])*(arr[r-1]-arr[l]))*4);
		while (atual >= area) 
		{
			resp = min(resp, abs(area - atual));
			atual -= (abs((arr[l]-arr[r])*(arr[l+1]-arr[r]))*4);
			++l;
		}

		resp = min(resp, abs(area - atual));
	}

	cout << resp << endl;

}







