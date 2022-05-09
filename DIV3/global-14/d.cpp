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
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, r, l, x;

int main()
{_
	cin >> t;
	while (t--)
	{
		multiset<int> left_, right_;
		priority_queue<int, vector<int>, greater<int> > left_f, right_f;
		cin >> n >> l >> r;
		ll resp = 0;
		for (int i = 0; i < l; i++)
		{
			cin >> x;
			left_.insert(x);
		}

		for (int i = 0; i < r; i++)
		{
			cin >> x;
			right_.insert(x);
		}

		for (int color = 1; color <= n; color++)
		{	
			while (right_.count(color) && left_.count(color)) 
			{
				right_.erase(right_.find(color));
				left_.erase(left_.find(color));
			}

			int k = left_.count(color);
			resp += (k>>1);
			if (k&1) left_f.push(1);
			k = right_.count(color);
			resp += (k>>1);
			if (k&1) right_f.push(1);
		}

		cout << resp << endl;

		while (!left_f.empty() && !right_f.empty())
		{
			left_f.pop(); right_f.pop();
			resp++;
 		}

 		resp += 2*(left_f.size());
 		resp += 2*(right_f.size());

 		cout << resp << endl;
	}
}













