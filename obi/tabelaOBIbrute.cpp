#include <iostream>

using namespace std;

int a[5], n, idx[3];

void resp()
{
    for (int i = 0; i < 5; i++) cout << a[i] << ' ';
    cout << endl;
}

int main()
{
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

    for (int i = 0; i < 5; i++) 
        if (a[i] == -1)
            idx[n++] = i;

    for (int i = 0; i <= 300; i++)
    {
        a[idx[0]] = i;
        if (n == 1)
        {
            if (a[0] == a[2] + a[3] + a[4] && a[1] == 3*a[2] + a[3])
            {
                resp();
                return 0;
            }
            continue;
        } 
        for (int j = 0; j <= 300; j++)
        {
            a[idx[1]] = j;
            if (a[0] == a[2] + a[3] + a[4] && a[1] == 3*a[2] + a[3])
            {
                resp();
                return 0;
            }
        }
    }


}