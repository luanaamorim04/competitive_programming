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
#include <deque>
#define ll long long
#define INF (1e9)
#define MAX ((int) (3e6) + 1)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, k, resp, arr[MAX], last;
deque<ll> maior, menor;

int main()
{_
	cin >> k >> n;
	last = 1;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		while (!menor.empty() && arr[menor.front()] >= arr[i]) menor.pop_front();
		while (!maior.empty() && arr[maior.front()] <= arr[i]) maior.pop_front();
		menor.push_front(i), maior.push_front(i);
		while (!menor.empty() && !maior.empty() && (arr[maior.back()] > arr[menor.back()] + k)) 
		{
			//cout << arr[maior.back()] << ' ' << arr[menor.back()] << endl;
			last = (menor.back() < maior.back() ? menor.back() : maior.back()) + 1;
			(menor.back() < maior.back() ? menor.pop_back() : maior.pop_back());
		}

		resp = max(resp, i - last + 1);
	}

	cout << resp << endl;
}









