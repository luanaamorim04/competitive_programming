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

ll n, value[101], qnt[101], price[101], resp, idx, dp[1<<20], x, soma;
vector<par> v;

int main()
{_
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> price[i];
	for (int i = 0; i < n; i++) cin >> value[i];
	for (int i = 0; i < n; i++) cin >> qnt[i];

	for (int i = 0; i < n; i++)
	{
		idx = 1, soma = 0;
		while (soma + idx <= qnt[i])
		{
			soma += idx;
			v.push_back({value[i]*idx, price[i]*idx});
			idx <<= 1;
		}
		
		v.push_back({value[i]*(qnt[i]-soma), price[i]*(qnt[i]-soma)});
	}

	for (int i = 0; i < v.size(); i++)
		for (int j = x; j >= v[i].second; j--)
			dp[j] = max(dp[j], dp[j-v[i].second] + v[i].first);
		
	cout << dp[x] << endl;
}













