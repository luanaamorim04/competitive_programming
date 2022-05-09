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

double t, n, arr[51];

int main()
{_
    cin >> t;
    while (t--)
    {
        int resp = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                while (arr[i]*2 < arr[i + 1])
                {
                    resp++;
                    arr[i]*=2;
                }
            }
            else
            {
                while (arr[i + 1]*2 < arr[i])
                {
                    resp++;
                    arr[i]/=2;
                }
            }
            
        }
        cout << resp << endl;
    }
}