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
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define sz(x) (ll) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll t, d, n, u, tot, resp;

int main()
{_
	cin >> t;
	for (int k = 1; k <= t; k++)
	{
		vector<ll> orders;
		priority_queue<par, vector<par>, greater<par> > pq;
		priority_queue<tuple<ll, ll, ll> , vector<tuple<ll, ll, ll> >, greater<tuple<ll, ll, ll> > > deliveries;
		cin >> d >> n >> u;
		for (int i = 0; i < d; i++)
		{
			ll a, b, c;
			cin >> a >> b >> c;
			deliveries.push({a, b, c});
		}

		for (int i = 0; i < n; i++)
		{
			ll a;
			cin >> a;
			orders.push_back(a);
		}

		resp = tot = 0;
		for (auto order : orders)
		{
			while (!deliveries.empty())
			{
				auto[t0, qnt, t1] = deliveries.top();
				if (t0 > order) break;
				deliveries.pop();

				tot += qnt;
				pq.push({t1, qnt});
				while (!pq.empty() && pq.top().first <= order)
				{
					tot -= pq.top().second;
					pq.pop();
				}
			}

			if (tot >= u)
			{
				resp++;
				tot -= u;
			}
			else
			{
				break;
			}
		}	

		cout << "Case #" << k << ": " << resp << endl;
	}
}













