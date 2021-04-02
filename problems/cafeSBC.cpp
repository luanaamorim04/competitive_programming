#include <iostream>

using namespace std;

int main()
{
    int p[3], total[3];
    cin >> p[0] >> p[1] >> p[2];

    total[0] = (2 * p[1]) + (4 * p[2]);
    total[1] = (2 * p[0]) + (2 * p[2]);
    total[2] = (4 * p[0]) + (2 * p[1]);
    int min = total[0];
    
    for (int i = 0; i < 3; i++)
    {
        if (total[i] < min)
            min = total[i];
    }

    cout << min << endl;
}