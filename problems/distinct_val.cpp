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

map<ll, int> mapa, mapa1;
int arr[MAX], last[MAX], prox[MAX], n, k, x;

int main()
{_
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        last[i] = mapa[arr[i]];
        mapa[arr[i]] = i;
    }

    for (int i = n; i >= 1; i--)
    {
        prox[i] = (mapa1.count(arr[i]) ? mapa1[arr[i]] : n + 1);
        mapa1[arr[i]] = i;
    }

    int l = 1, r = 1, dif = 1;
    ll resp = 1;
    while (l < n)
    {
        if (dif < k && r < n && last[r + 1] < l) 
        {
            r++, dif++, resp++;
        }
        else if (dif <= k && r < n && last[r + 1] >= l)
        {
            r++, resp++;
        }
        else if (dif == k || r == n)
        {
            if (prox[l] > r) dif--;
            l++;
            r = max(r, l);
            dif = max(dif, 1);
            resp += max(1, r-l+1);
        }

        //cout << l << ' ' << r << ' ' << dif << endl;
    }

    cout << resp << endl;
}