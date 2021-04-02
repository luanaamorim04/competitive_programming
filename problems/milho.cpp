#include <iostream>

using namespace std;

int main()
{
    int n, c, s, j, pos = 1, res = 0;
    cin >> n >> c >> s;
    if (s == 1) res++;
    for (int i = 0; i < c; i++)
    {
        cin >> j;
        if (j == 1)
        {
            pos++;
            if (pos > n) pos = 1;
        }
        else
        {
            pos--;
            if (pos < 1) pos = n;
        }

        if (pos == s) res++;
        
    }

    cout << res << endl;
}