#include <iostream>
#define _ std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

long long psa[2050][2050], slider;
string s;

int main()
{_
    int index = 0, div[2050], i, j, t = 1, n, x, g;
    cin >> n >> g;

    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            div[index] = i;
            index++;
        }
        for (j = 1; j <= n; j++)
        {
            cin >> x;
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + x;
        }
    }

    index = 0;
    for (i = t; i <= n; i += t)
    {
        for (j = t; j <= n; j += t)
        {
            slider = psa[i][j] - psa[i - t][j] - psa[i][j - t] + psa[i - t][j - t];
            if (slider < g)
            {
                t = div[++index];
                i = 0;
                break;
            }
        }
    }

    n = n * n;
    t = t * t;

    std::cout << (n / t) << endl;
}