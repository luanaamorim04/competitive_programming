#include <iostream>

int fact(int x)
{
    if (x <= 1) return 1;
    return x * fact(x - 1);
}

int main()
{
    std::cout << fact(9) << '\n';
}