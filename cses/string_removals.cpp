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

using namespace std;

string s;
ll last['z' + 1], resp[1<<20], psa[1<<20];

int main()
{_
	cin >> s;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (!last[s[i]])
			resp[i] = (psa[i+1] + 1) % MOD;
		else
			resp[i] = (psa[i+1] - psa[last[s[i]] + 1] + MOD) % MOD;
		
		last[s[i]] = i;
		psa[i] = (resp[i] + psa[i+1]) % MOD;
	}

	cout << psa[0] << endl;
}





