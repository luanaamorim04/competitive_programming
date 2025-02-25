#include <iostream> 
#include <vector> 
#define MAXN (int) (2e5 + 10)
#define iii tuple<int, int, int> 

using namespace std;

int resp, pai[MAXN], n, m, a, b, c;
vector<iii> arr;

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) pai[i] = i;
	while (m--)
	{
		cin >> a >> b >> c;
		arr.push_back({c, a, b});
	}

	sort(arr.begin(), arr.end());

	for (auto[c, a, b] : arr)
	{
		if (find(a) == find(b)) continue;
		pai[find(a)] = find(b);
		resp += c;
	}

	cout << resp << endl;
}
