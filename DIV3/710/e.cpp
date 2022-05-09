#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
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

multiset<int> ma, me;
int t, n, arr[1<<20], p[1<<20];

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            ma.insert(-(i + 1));
            me.insert(i + 1);
        }

        for (int i = 0; i < n; i++)
        {
            if (!p[arr[i]]) 
            {
                cout << arr[i] << ' ';
                p[arr[i]] = 1;
                me.erase(arr[i]);
            }
            else
            {
                cout << *me.begin() << ' ';
                me.erase(me.begin());
            }
        }
        cout << endl;

        for (int i = 0; i < n; i++) // maior
        {
            cout << -(*ma.lower_bound(-arr[i])) << ' ';
            ma.erase(ma.lower_bound(-arr[i]));
            p[i + 1] = 0;
        }

        cout << endl;
    }
}
