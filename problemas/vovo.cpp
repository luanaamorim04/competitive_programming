#include <iostream>

int main()
{
    int n, s;
    std::cin >> n >> s;
    int min = s;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        s += a;
        if (s < min) min = s; 
    }

    std::cout << min;
}