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

ll n, r, a, b, deltax, deltay, resp, qtd;
vector<pair<ll, ll> > v;
priority_queue<ll, vector<ll>, greater<ll> > pq;

pair<ll, ll> tempo(double x, double y, double dx, double dy)
{
	int ok = 0;
	double a = (dx*dx) + (dy*dy);
	double b = (2*dx*x) + (2*dy*y);
	double c = (x*x) + (y*y) - (r*r);
	double delta = (b*b) - (4*a*c);
	if (delta<0) return {INF, INF};
	double r1 = (-b - sqrt(delta)) / (2*a);
	double r2 = (-b + sqrt(delta)) / (2*a);
	
	for (ll i = max((double)0, r1-2); i <= r1+2; i++)
	{
		ll px = x + (dx*i);
		ll py = y + (dy*i);
		if ((px*px) + (py*py) <= r*r) 
		{
			ok = 1;
			r1 = i;
			break;
		}
	}

	for (ll i = r2+2; i >= max((double)0, r2-2); i--)
	{
		ll px = x + (dx*i);
		ll py = y + (dy*i);
		if ((px*px) + (py*py) <= r*r) 
		{
			ok = 1;
			r2 = i;
			break;
		}
	}

	if (!ok) return {INF, INF};
	return {max(0LL, (ll)r1), (ll)r2};
}

int main()
{_
	cin >> n >> r;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b >> deltax >> deltay;
		deltax -= a;
		deltay -= b;
		v.push_back(tempo(a, b, deltax, deltay));
	}

	sort(all(v));
	for (auto[l, r] : v)
	{
		if (l == INF && r == INF) break;
		while (!pq.empty() && pq.top() < l) pq.pop(), qtd--;
		qtd++;
		resp = max(resp, qtd);
		pq.push(r);
	}

	cout << resp << endl;

}














