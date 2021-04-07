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
#define ll long long
#define INF 10000009
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int memo[3100][100][100], n, arr[100], soma;

int f(int tot, int idx, int qnt)
{
	//if (tot > (soma>>1)) return INF;
	if (idx == n) return memo[tot][idx][qnt] = (qnt == 0 ? abs(soma-(2*tot)) : INF);

	if (memo[tot][idx][qnt] != -1) return memo[tot][idx][qnt];

	return memo[tot][idx][qnt] = min(f(tot + arr[idx], idx + 1, qnt - 1), f(tot, idx + 1, qnt));
}

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> arr[i];
		soma += arr[i];
	}

	memset(memo, -1, sizeof(memo));
	
	cout << f(0, 0, (n>>1)) << endl;
}

