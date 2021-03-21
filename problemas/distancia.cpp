#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[n], res;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    int melhor = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, p[i] + i - melhor + p[melhor]);
        if (p[i] > i - melhor + p[melhor])
            melhor = i;
    }


    cout << res << '\n';

}