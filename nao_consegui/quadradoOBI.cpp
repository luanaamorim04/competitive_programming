#include <iostream>
#include <set>
#define INF (int) 1e9 + 7

using namespace std;

int q[3][3], ideal, linhas, colunas[3], bc[3], bl[3], c[3], l[3];

int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> q[i][j];
            c[j] += q[i][j];
            l[i] += q[i][j];
            if (!q[i][j]) 
            {
                bc[j]++;
                bl[i]++;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (!bc[j]) ideal = q[0][j] + q[1][j] + q[2][j];

        if (!bl[i]) ideal = q[i][0] + q[i][1] + q[i][2];
    }

    if (!ideal)
    {
        for (int i = 0; i < 3; i++)
        {
            ideal += q[i][i];
            if (!q[i][i]) 
            {
                ideal = 0;
                break;
            }
        }
    }

    if (!ideal)
    {
        ideal = q[0][2] + q[1][1] + q[2][0];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!q[i][j])
            {
                if (bc[j] <= 1)
                {
                    q[i][j] = ideal - c[j];
                }
                else if (bl[i] <= 1)
                {
                    q[i][j] = ideal - l[i];
                }
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!q[i][j])
            {
                if (bc[j] <= 1)
                {
                    cout << ideal - c[j] << ' ';
                }
                else
                {
                    cout << ideal - l[i] << ' ';
                }
            }
            else
            {
                cout << q[i][j] << ' ';
            }
        }
        cout << endl;
    }
}