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
#include <bitset>
#include <numeric>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct space
{
	double tam;
	ll pos, qnt;

	bool operator<(space q) const{
		return (tam == q.tam ? pos > q.pos : tam < q.tam); 
	} 
	bool operator>(space q) const{
		return (tam == q.tam ? pos < q.pos : tam > q.tam); 
	} 
};

ll n, q, x, last;
queue<space> q1, q2;
ll idx, tirei;
par tempo[MAX], resp[MAX];
vector<space> v;

int main()
{_
	cin >> n >> x >> q;
	cin >> last;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		v.push_back({(double) x-last, last, 1});
		last = x;
	}

	sort(all(v));
	for (int i = v.size() - 1; i >= 0; i--)
		q1.push(v[i]);

	q1.push({0, 0, 0});

	for (int i = 0; i < q; i++)
	{
		cin >> tempo[i].first;
		tempo[i].second = i;
	}

	sort(tempo, tempo+q);
	while (idx != q)
	{
		if (!q2.empty() && q2.front() > q1.front())
		{
			auto [a, b, c] = q2.front(); q2.pop();
			tirei += c;
			while (tempo[idx].first <= tirei && idx != q)
			{
				ll num = c*((2*b) + (2*a*(c+(tempo[idx].first-tirei)-1)) + a), den = 2*c;
				resp[tempo[idx++].second] = {num/gcd(num, den), den/gcd(num, den)};
			}
			q2.push({a/2, b, c*2});
		}
		else
		{
			auto [a, b, c] = q1.front(); q1.pop();
			tirei += c;
			while (tempo[idx].first <= tirei && idx != q)
			{
				ll num = c*((2*b) + (2*a*(c+(tempo[idx].first-tirei)-1)) + a), den = 2*c;
				resp[tempo[idx++].second] = {num/gcd(num, den), den/gcd(num, den)};
			}
			q2.push({a/2, b, c*2});
		}
	}

	for (int i = 0; i < q; i++)
		cout << resp[i].first << '/' << resp[i].second << endl;
}















