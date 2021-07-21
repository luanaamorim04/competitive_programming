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
#define INF (1e15)
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

ll n, c, h[MAX], dp[MAX], A[MAX], B[MAX];
int tam, idx;

void update(ll a, ll b)
{
	while (tam > 1 && ((B[tam-2]-B[tam-1])*(a-A[tam-1])) <= ((B[tam-1]-b)*(A[tam-1]-A[tam-2])))
	{
		//cout << A[tam-1] << ' ' << B[tam-1] << endl;
		tam--;
	}
	A[tam] = a;
	B[tam] = b;
	tam++;
	//cout << tam << endl;
	//cout << a << ' ' << b << endl;
	// W(a);
	// W(b);
}

ll query(ll x)
{
	idx = min(idx, tam-1);
	while (idx + 1 < tam && ((A[idx]*x) + B[idx]) >= ((A[idx+1]*x) + B[idx+1]))
		idx++;

	return (A[idx]*x) + B[idx];
}

int main()
{_
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> h[i];

	update(-2*h[n-1], (h[n-1]*h[n-1]));
	for (int i = n-2; i >= 0; i--)
	{
		dp[i] = query(h[i]) + (h[i]*h[i]) + c;
		//cout << tam << endl;
		update(-2*h[i], (h[i]*h[i]) + dp[i]);
	}

	// for (int i = n-1; i >= 0; i--)
	// 	cout << dp[i] << ' ';
	// cout << endl;
	cout << dp[0] << endl;
}







