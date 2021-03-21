#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <bitset>
#include <cmath> 
#include <iomanip>
#include <map>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, arr[100003];
long long resp, qnt, tmp;

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        arr[n] = resp = 0;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < 22; i++)
        {
            qnt = tmp = 0;
            for (int j = 0; j <= n; j++)
            {
                if (arr[j] & (1<<i)) qnt++;
                else tmp += ((qnt*(qnt + 1))>>1LL), qnt = 0;
            }

            resp += (tmp<<i);
        }

        cout << resp << endl;
    }
}