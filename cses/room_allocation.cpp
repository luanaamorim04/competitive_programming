#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, a, b, room;
vector<par> arr, r;
set<par> s;
map<pair<par, int>, int > resp;
map<par, int> freq;

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr.push_back({a, b});
		r.push_back(arr[i]);
	}

	sort(all(arr));
	for (par x : arr)
	{
		freq[x]++;
		auto it = s.lower_bound({-x.first + 1, 0});
		if (it != s.end())
		{
			s.erase(it), s.insert({-x.second, (*it).second});
			resp[{x, freq[x]}] = (*it).second;
		}
		else
		{
			s.insert({-x.second, ++room});
			resp[{x, freq[x]}] = room;
		}
	}

	freq.clear();

	cout << room << endl;
	for (par x : r)
		cout << resp[{x, ++freq[x]}] << ' ';
	cout << endl;
	


















}
