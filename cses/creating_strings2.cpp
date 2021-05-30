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

ll inv(ll a, ll b){
    return a>1 ? b-inv(b%a,a)*b/a : 1;
}

ll fat[1<<20], freq[1000], resp;
string s;

int main()
{_
	cin >> s;
	fat[0] = 1;
	for (char i : s) freq[i]++;
	for (int i = 1; i <= s.size(); i++)
		fat[i] = (fat[i-1]*i) % MOD;

	resp = fat[s.size()];
	for (int i = 'a'; i <= 'z'; i++)
		resp = (resp*inv(fat[freq[i]], MOD)) % MOD;

	cout << resp << endl;
}












