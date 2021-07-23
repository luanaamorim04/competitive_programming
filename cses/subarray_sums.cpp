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
#define INF (ll) (1e17)
#define MAX (int) (2e6 + 5)
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

ll n, k, psa[3005], dp[3005][3005], idx, tam, A[MAX], B[MAX];

void update(ll a, ll b)
{
	while (tam > 1 && ((B[tam-2]-B[tam-1])*(a-A[tam-2])) <= ((B[tam-2]-b)*(A[tam-1]-A[tam-2])))
		tam--;

	A[tam] = a;
	B[tam] = b;
	tam++;
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
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> psa[i];
		psa[i] += psa[i-1];
	}

	for (int i = n+1; i >= 1; i--)
	{
		for (int j = 0; j <= k+1; j++)
			dp[i][j] = INF;
	}

	dp[n+1][k+1] = 0;
	for (int j = k; j >= 1; j--)
	{
		for (int i = n; i >= 1; i--)
		{
			update(-2*psa[i], dp[i+1][j+1] + (psa[i]*psa[i]));
			dp[i][j] = (psa[i-1]*psa[i-1]) + query(psa[i-1]);
		}

		tam = idx = 0;
	}

	cout << dp[1][1] << endl;
}














