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
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a, resp, tmp, n;

int main()
{_
    while (cin >> n && n)
    {
        tmp = resp = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            tmp = max(0, tmp + a);
            resp = max(resp, tmp);
        }

        if (resp) cout << "The maximum winning streak is " << resp << '.' << endl;
        else cout << "Losing streak." << endl;
    }
}