#include <iostream>

int main()
{
    int f[3], h, l;

    std::cin >> f[0] >> f[1] >> f[2] >> h >> l;

    for (int i = 0; i < 3; i++)
    {
        if (f[i] > h) continue;
        for (int j = 0; j < 3; j++)
        {
            if (f[j] < l && j != i)
            {
                std::cout << 'S';
                return 0;
            }
        }
    }

    std::cout << 'N';

}