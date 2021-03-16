#include <iostream>
#include <vector>

using namespace std;

int cubo[6][3][3], aux, counter;

void algorithm(char c);
int check(void);

int main()
{
    string alg;
    cin >> alg;

    // preencher o cubo com as cores
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                cubo[i][j][k] = i + 1;

    while (true)
    {
        for (int i = 0; i < alg.size(); i++)
        {
            algorithm(alg[i]);
        }

        if (check())
        {
            cout << counter << endl;
            return 0;
        }
    }
}

int check(void)
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                if (cubo[i][j][k] != i + 1)
                    return 0;

    return 1;
}

void rotate(int dir, int x)
{
    if (dir)
    {
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
            {
                cubo[x][j][k] = cubo[x][j][k];
            }
    }
}

void algorithm(char c)
{
    if (c == 'R')
    {
        
    }
    if (c == 'r')
    {

    }
    if (c == 'U')
    {

    }
    if (c == 'u')
    {

    }
    if (c == 'L')
    {

    }
    if (c == 'l')
    {

    }
    if (c == 'D')
    {

    }
    if (c == 'd')
    {

    }
    if (c == 'B')
    {

    }
    if (c == 'b')
    {

    }
    if (c == 'F')
    {

    }
    if (c == 'f')
    {

    }
    return;
}