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
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, p, fat[200];

ll fexpo(ll b, ll e)
{
	ll resp = 1;
	while (e)
	{
		if (e&1) resp = (resp * b) % p;
		b = (b * b) % p;
		e>>=1;
	}
	return resp;
}

int impar(int x, int y)
{
	ll resp = 1;
	vector<int> dig1, dig2;
	while (x)
	{
		dig1.push_back(x%p);
		x /= p;
	}

	while (y)
	{
		dig2.push_back(y%p);
		y /= p;
	}

	while (dig1.size() > dig2.size()) dig2.push_back(0);
	while (dig2.size() > dig1.size()) dig1.push_back(0);

	for (int i = 0; i < dig1.size(); i++)
	{
		if (dig2[i] > dig1[i]) resp = 0;
		for (int j = dig1[i]; j > dig1[i]-dig2[i]; j--) resp = (resp*j) % p;
		resp = (resp * fexpo(fat[dig2[i]], p)) % p;
	}

	return resp;
}

int main()
{_
	cin >> n >> p;
	fat[0] = 1;
	for (int i = 1; i <= p; i++) fat[i] = (i*fat[i-1]) % p;

	for (int i = 0; i <= n; i++)
	{
		cout << !impar(n, i);
	}
	cout << endl;
}
