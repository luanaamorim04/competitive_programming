#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long l[1000], fat[21], ans;
string s;

int main()
{_  
    fat[0] = 1;
    for (int i = 1; i <= 20; i++)
        fat[i] = fat[i - 1] * i;

    cin >> s;
    ans = fat[s.size()];
    for (int i = 0; i < s.size(); i++)
        l[s[i]]++;

    for (int i = 'a'; i <= 'z'; i++)
        if (l[i]) ans /= fat[l[i]];

    cout << ans << endl;
}