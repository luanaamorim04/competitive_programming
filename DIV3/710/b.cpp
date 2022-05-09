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

int t, n, k, resp, last;
string s;
vector<int> pos;

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*') pos.push_back(i);
        }
        resp = 1, last = 0;

        for (int i = 1; i < pos.size() - 1; i++)
        {
            if (pos[last] + k < pos[i + 1]) last = i, ++resp;
        }
        if (last != pos.size() - 1) resp++;
        cout << resp << endl;
        pos.clear();
    }
}
