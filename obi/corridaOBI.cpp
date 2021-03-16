#include<iostream>

int a, b, x, res, k, l;
int main()
{
    std::cin >> a >> b;
    res = 99999999;
    for (int i = 0; i < a; i++)
    {
        k = 0;
        for (int j = 0; j < b; j++)
        {
            std::cin >> x;
            k += x;
        }

        if (res > k)
        {
            res = k;
            l = i;
        }
    }

    std::cout << l+1;
}