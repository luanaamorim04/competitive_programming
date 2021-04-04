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
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

priority_queue<par, vector<par>, greater<par> > pq;
int n;

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++) pq.push({0, i});

	while (!pq.empty())
	{
		par a = pq.top();
		pq.pop();
		pq.push({a.first + 1, a.second});
		par b = pq.top();
		pq.pop();
		cout << b.second << ' ';
	}	
	cout << endl;
}
























