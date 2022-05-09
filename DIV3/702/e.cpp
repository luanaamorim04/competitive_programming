#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

map<long long, int> mapa;
long long t, n, arr[200001], psa[200001], id[200001], idx, ok, resp;

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        resp = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            id[i] = arr[i];
        }

        sort(arr+1, arr+1+n);

        for (int i = 1; i <= n; i++)
            psa[i] = psa[i - 1] + arr[i];

        for (int i = n; i >= 1; i--)
        {
            mapa[arr[i]] = 1;
            resp++;
            if (arr[i] > psa[i - 1]) break;
        }

        cout << resp << endl;
        for (int i = 1; i <= n; i++)
            if (mapa[id[i]]) cout << i << ' ';

        cout << endl;
        mapa.clear();
    }   
}