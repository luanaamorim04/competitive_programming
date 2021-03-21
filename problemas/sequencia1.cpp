#include <iostream>

int main()
{
    int tmp[] = {12, 14, 18};
    for (int i = 0; i <= 20; i++)
    {
        std::cout << "a = " << tmp[0] << " <-> b = " << tmp[2] << '\n';

        std::cout << "a = " << tmp[1] << " <-> b = " << tmp[1] + 2 << '\n';

        std::cout << "a = " << tmp[2] << " <-> b = " << tmp[0] << '\n';

        tmp[0]++;
        tmp[1]++;
        tmp[2]++;
    }
}