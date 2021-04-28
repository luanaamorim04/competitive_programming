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
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;

int n, k, ft[1<<20], tam, pos;
ordered_set s;

int main()
{_
	cin >> n >> k;
	tam = ++n;
	for (int i = 1; i <= n; i++)
		s.insert(i);

	while (--tam)
	{
		pos = (pos + k) % (tam);
		cout << *s.find_by_order(pos) << ' ';
		s.erase(s.find_by_order(pos));
	}
	cout << endl;
}









