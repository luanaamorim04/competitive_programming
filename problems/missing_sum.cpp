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

ll psa[1<<20], n, a[1<<20], resp;

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a+1, a+1+n);

    for (int i = 1; i <= n; i++)
    {
        if (a[i] > psa[i] + 1) 
        {
            cout << psa[i] + 1 << endl;
            return 0;
        }
        psa[i + 1] = psa[i] + a[i];
    }
    cout << psa[n + 1] + 1 << endl;
}
