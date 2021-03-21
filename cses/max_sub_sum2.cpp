#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 1e10
#define MAX 300000
#define MOD 1000000007
#define par pair<ll, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

priority_queue<par, vector<par>, greater<par> > pq;
ll psa[1<<20], resp, menor[1<<20], dif;

/*
	________l__r___i
*/

int main()
{_
	int n, a, b;
	cin >> n >> a >> b;

	resp = -(1e15);
	for (int i = 1; i <= n; i++)
	{
		cin >> psa[i];
		psa[i] += psa[i - 1];

		int r = max(0, i - a), l = max(0, i - b);
		pq.push(par(psa[r], r));

		while (pq.top().second < l) pq.pop();

		if (i >= a) resp = max(resp, psa[i] - pq.top().first);
	}

	cout << resp << endl;
}
