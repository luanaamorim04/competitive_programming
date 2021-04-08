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
#define ll long long
#define INF (1e9) + 1
#define esq(x) (x<<1)
#define dir(x) ((x<<1) + 1)
#define MAX (int) (1e6 + 1)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

deque<int> maior;
int n, k, arr[MAX], resp, maxn, idx;
priority_queue<par> segundo;

int main()
{_
	cin >> n >> k;
	resp = INF;
	for (int i = 1; i <= n; i++) 
	{
		cin >> arr[i];
		if (i < k) 
		{
			while (!maior.empty() && arr[i] >= arr[maior.back()])
			{
				segundo.push({arr[maior.back()], maior.back()});
				maior.pop_back();
			}
			maior.push_back(i);
		}
	}

	if (k==1) 
	{
		cout << 0 << endl;
		return 0;
	}
	
	for (int i = k; i <= n; i++)
	{
		while (maior.front() < (i - k + 1)) maior.pop_front();

		while (!maior.empty() && arr[i] >= arr[maior.back()])
		{
			segundo.push({arr[maior.back()], maior.back()});
			maior.pop_back();
		}

		maior.push_back(i);

		int maxn = arr[maior.front()];

		while (!segundo.empty() && segundo.top().second < (i-k+1)) segundo.pop();

		int s1 = (maior.size() > 1 ? arr[maior[1]] : 0);
		int s2 = (!segundo.empty() ? segundo.top().first : 0);

		resp = min(resp, (maxn-max(s1, s2))>>1);
		//cout << maior.front() << ' ' << maior[1] << ' ' << segundo.top().first << endl;
	}

	cout << resp << endl;
}














