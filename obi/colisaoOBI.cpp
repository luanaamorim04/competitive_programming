#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long r1[4], r2[4];
    bool colisao = false;

    for (int i = 0; i < 4; i++)
    {
        cin >> r1[i];
    }

    for (int i = 0; i < 4; i++)
        cin >> r2[i];

    long long width1 = r1[2];
    long long height1 = r1[3];
    long long pos1x = r1[0];
    long long pos1y = r2[1];

    long long width2 = r2[2];
    long long height2 = r2[3];
    long long pos2x = r2[0];
    long long pos2y = r2[1];

    if (pos1x >= pos2x && pos1x <= width2)
        if (pos1y >= pos2y && pos1y <= height2)
            colisao = true;

    if (pos2x >= pos1x && pos2x <= width1)
        if (pos2y >= pos1y && pos2y <= height1)
            colisao = true;

    if (colisao == true)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}
