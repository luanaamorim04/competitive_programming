#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#define int long long
#define MAXN (int) (1e6 + 5)
#define iii tuple<int, int, int>
#define all(v) v.begin(), v.end()
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct Func
{
	int a, b;
};

Func cht[MAXN];
int n, dp, resp, tam, idx;

double inter(Func e, Func d)
{
	return (double)(e.b - d.b)/(double)(d.a - e.a);
}

void update(int a, int b)
{
	while (tam > idx+1 && inter(cht[tam-2], cht[tam-1]) > inter(cht[tam-1], {a, b}))
		tam--;

	cht[tam].a = a;
	cht[tam].b = b;
	tam++;
}

int query(int x)
{
	while (idx + 1 < tam && ((cht[idx].a*x) + cht[idx].b) <= ((cht[idx+1].a*x) + cht[idx+1].b))
		idx++;

	return (cht[idx].a*x) + cht[idx].b;
}

int32_t main()
{_
	cin >> n;
	vector<iii> v(n);
	for (auto &[x, y, a] : v)
		cin >> x >> y >> a;

	sort(all(v));
	update(0, 0);
	for (auto[x, y, a] : v)
	{
		dp = query(-y) + y*x - a;
		resp = max(resp, dp);
		update(x, dp);
	}

	cout << resp << endl;
}
