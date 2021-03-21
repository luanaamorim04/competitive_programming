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
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> v;
map<int, int> val;
int n, a, b, psa[1<<20], resp;
par arr[1<<20];

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		v.push_back(a), v.push_back(b);
		arr[i] = par(a, b);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= v.size(); i++)
	{
		val[v[i - 1]] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		psa[val[arr[i].first]]++;
		psa[val[arr[i].second] + 1]--;
	}

	for (int i = 1; i <= v.size(); i++)
	{
		psa[i] += psa[i - 1];
		resp = max(resp, psa[i]);
	}

	cout << resp << endl;
}
