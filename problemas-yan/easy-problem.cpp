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
#define dbug(x) cout << (#x) << " -> " << x << endl
#define ll long long
#define INF (1e15)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, memo[MAX][5], custo[MAX];
string s;
vector<int> v;
map<char, int> val;
vector<par> arr;

ll f(int idx, int lis)
{
	if (lis == 4) return INF;
	if (idx == sz(arr)) return 0;
	if (~memo[idx][lis]) return memo[idx][lis];
	int c = arr[idx].first;
	ll resp = min(custo[arr[idx].second] + f(idx+1, lis), f(idx+1, (lis==c-1?c:lis)));

	return memo[idx][lis] = resp;
}

int main()
{_
	cin >> n >> s;
	val['h'] = 1;
	val['a'] = 2;
	val['r'] = 3;
	val['d'] = 4;
	for (int i = 0; i < n; i++)
		cin >> custo[i];
	for (int i = 0; i < sz(s); i++)
		if (val.find(s[i]) != val.end())
			arr.push_back({val[s[i]], i});

	//dp[i][j] = min cost to get
	//to pos i with lis j
	memset(memo, -1, sizeof memo);
	cout << f(0, 0) << endl;
}









