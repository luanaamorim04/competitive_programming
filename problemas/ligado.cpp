#include <iostream>

int res[110000][2], out[1000000];

int main()
{
    int n, m, t, a, b, index = 0, index2 = 0;
    bool tr;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        std::cin >> t >> a >> b;
        if (t == 1)
        {
            res[index][0] = a;
            res[index][1] = b;
            index++;
        }
        else
        {
            tr = false;
            for (int j = 0; j < index; j++)
            {
                if ((a == res[j][0] && b == res[j][1]) || (b == res[j][0] && a == res[j][1]))
                {
                    tr = true;
                    break;
                }
            }

            out[index2] = tr;
            index2++;
        }
    }

    for (int i = 0; i < index2; i++)
        std::cout << out[i] << '\n';

}


    