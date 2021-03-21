#include <iostream>

using namespace std;

struct eventos
{
    bool v;
    int id;
};

int main()
{
    int e, i, v;
    cin >> e >> i >> v;
    eventos  causa[1000], cons[1000];
    bool check[e];
    check[v - 1] = true;
   

    for (int j = 0; j < i; j++)
    {
        cin >> causa[j].id >> cons[j].id;
    }

    for (int i = 0; i < e; i++)
    {
        if (check[i] == false) continue;
        for (int j = 0; j < i; j++)
        {
            if (check[i] == causa)
        }
    }

}