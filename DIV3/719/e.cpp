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
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, resp;
string s;
vector<int> pos;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		resp = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '*') pos.push_back(i);

		int l = 0, r = pos.size() - 1, qnt_l = 1, qnt_r = 1;

		while (l < r)
		{
			while (pos[l]+1 == pos[l+1] && l < n) l++, qnt_l++;
			while (pos[r]-1 == pos[r-1] && r > 0) r--, qnt_r++;

			if (l >= r) continue;

			if ((pos[l+1]-pos[l]-1)*qnt_l > (pos[r]-pos[r-1]-1)*qnt_r)
			{
				resp += (pos[r]-pos[r-1]-1)*qnt_r;
				qnt_r++, r--;
			}
			else
			{
				resp += (pos[l+1]-pos[l]-1)*qnt_l;
				qnt_l++, l++;
			}
		}

		cout << resp << endl;
		pos.clear();
	}
}











