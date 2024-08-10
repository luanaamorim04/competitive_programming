#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <map>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define MOD (int) (1e9 + 7)
#define INF (int) (1e18 + 10)
#define all(x) x.begin(), x.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)

using namespace std;

double arr[MAXN], soma, menor, des, resp, quad;
int n, k;

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i < k; i++) soma += arr[i], quad += (arr[i]*arr[i]);

	menor = INF;
	for (int i = k; i <= n; i++)
	{
		soma -= arr[i-k];
		soma += arr[i];
		quad -= (arr[i-k]*arr[i-k]);
		quad += (arr[i]*arr[i]);
		
		des = (quad*k -soma*soma);
		if (des < menor) menor = des, resp = i;
	}

	cout << resp-k+1 << ' ' << resp << endl;
	cout << fixed << setprecision(14) << (sqrt(menor)/k) << endl;
}



