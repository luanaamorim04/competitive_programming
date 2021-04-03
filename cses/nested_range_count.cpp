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

int n, y;
par points[1<<20], resp[1<<20];
map<par, int> contido, contem;

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> points[i].first >> points[i].second;
		points[i].second *= -1;
		resp[i] = points[i];
	}

	sort(points, points+n);
	y = ((1e9) + 9);
	for (int i = n - 1; i >= 0; i--)
	{
		contem[points[i]] = (-points[i].second >= y);
		y = min(y, -points[i].second);
	}

	y = 0;
	for (int i = 0; i < n; i++)
	{
		contido[points[i]] = (-points[i].second <= y);
		y = max(y, -points[i].second);
	}

	for (int i = 0; i < n; i++)
		cout << contem[resp[i]] << ' ';
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << contido[resp[i]] << ' ';
	cout << endl;
}









