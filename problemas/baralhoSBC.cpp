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

int n, pos[1<<20], resp, x, p;

int main()
{_
	cin >> n;
	for (int i = 2; i <= n; i+=2)
		pos[++p] = i; 

	for (int i = 1; i <= n; i+=2)
		pos[++p] = i;

	x = pos[n];
	while (x != n)
	{
		x = pos[x];
		++resp;
	}

	cout << resp + 1 << endl;
}
