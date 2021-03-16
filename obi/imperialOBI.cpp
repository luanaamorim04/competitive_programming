#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <set>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a, b, last, arr[505], maxn, n, counter;

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    maxn = 1;
    for (int i = 1; i <= n; i++)
    {
        a = i; 
        for (int j = i + 1; j <= n; j++)
        {
            b = j;
            counter = 0;
            last = 0;
            for (int k = 0; k < n; k++)
            {
                if (arr[k] == a && last != a)
                {
                    last = a;
                    counter++;
                }
                else if (arr[k] == b && last != b)
                {
                    last = b;
                    counter++;
                }
            }

            maxn = max(maxn, counter);
        }
    }

    cout << maxn << endl;
}