#include <iostream>

using namespace std;

bool infectados[1010];

int main()
{
    int n, m, i, r, id, a, count = 1;
    cin >> n >> m >> i >> r;
    infectados[i] = 1;

    for (int j = 0; j < m; j++)
    {
        cin >> a;
        int reuniao[a];
        bool inf = false;
        for (int h = 0; h < a; h++)
        {
            cin >> id;
            if (j + 1 < r)
                continue;

            reuniao[h] = id;
            if (infectados[id] == 1 && inf == false)
            {
                inf = true;
                for (int k = 0; k < h; k++)
                {
                    if (infectados[reuniao[k]] == 1)
                       continue;

                    count++;
                    infectados[reuniao[k]] = 1;
                }
            }
            else if (inf == true && infectados[id] == 0)
            {
                count++;
                infectados[id] = 1;
            }
        }
    }

    cout << count << endl;
}