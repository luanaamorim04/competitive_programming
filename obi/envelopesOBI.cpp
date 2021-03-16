#include <iostream>
#include <algorithm>

using namespace std;

int in[1000009];

int main()
{
    int n, t, min = 9999999;

    cin >> n >> t;

    for (int i = 0; i < n; i++)
        cin >> in[i];

    for (int i = 1; i <= t; i++)
    {
        if (count(in, in + n, i) < min)
            min = count(in, in + n, i);
    }

    cout << min << endl;
}