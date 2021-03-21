#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int res[1000000], n;
string s;

int main()
{
    int min = 0;
    cin >> n;
    cin >> s;
    res[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == 'A') res[i] = res[i - 1] + 1;
        else res[i] = res[i - 1] - 1;
        if (min > res[i]) min = res[i];
    }

    for (int i = 0; i < n; i++)
        cout << res[i] - min << ' ';
}