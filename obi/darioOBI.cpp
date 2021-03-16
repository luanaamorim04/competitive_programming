#include <iostream>

int main()
{
    int n, a , b, d = 0, x = 0;
    std::cin >> n;
    for (int i = 0; i < n ; i++)
    {
        std::cin >> a >> b;
        for (int i = 0; i < 5; i++)
        {
            if (a == i && (b == i + 2 || b == i + 1))
            {
                d++;
                break;
            }
            else if ((a >= 3 && b == 0) || (a == 4 && b == 1))
            {
                d++;
                break;
            }
            else if (b == i && (a == i + 2 || a == i + 1))
            {
                x++;
                break;
            }
            else if ((b >= 3 && a == 0) || (b == 4 && a == 1))
            {
                x++;
                break;
            }
        }
    }

    if (d > x) std::cout << "will\n";
    else std::cout << "11\n";
}