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

int n, a, b, resp, ft[1<<20];
par arr[1<<20];
vector<int> v;
map<int, int> val;

int query(int idx)
{
	int ans = 1;
	while (idx > 0)
	{
		ans = max(ans, ft[idx]);
		idx -= lsb(idx);
	}
	return ans;
}

void update(int idx, int val)
{
	while (idx <= v.size())
	{
		ft[idx] = max(ft[idx], val);
		idx += lsb(idx);
	}
}

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		v.push_back(a), v.push_back(b);
		arr[i] = par(a, b);
	}

	sort(arr+1, arr+1+n);
	sort(v.begin(), v.end());
	for (int i = 1; i <= v.size(); i++)
	{
		val[v[i - 1]] = i;
	}

	for (int i = 1; i <= n; i++)
	{	
		update(val[arr[i].second], query(val[arr[i].first]) + 1);
		resp = max(resp, query(val[arr[i].first]));
	}

	cout << resp << endl;















}
