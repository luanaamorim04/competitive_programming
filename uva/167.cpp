#include <iostream>

using namespace std;

int t, chess[65][65], d1, d2, row, arr[10], maior;

void resp(int linha, int ans)
{
    if (linha == 8) 
    {
        maior = max(maior, ans);
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (row & (1<<i) || d1 & (1<<(i - linha + 7)) || d2 & (1<<(linha + i))) continue;
        row |= (1<<i);
        d1 |= (1<<(i - linha + 7));
        d2 |= (1<<(linha + i));
        resp(linha + 1, ans + chess[i][linha]);
        row -= (1<<i);
        d1 -= (1<<(i - linha + 7));
        d2 -= (1<<(linha + i));
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        maior = 0;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> chess[i][j];
        d1 = d2 = row = 0;
        resp(0, 0);
        cout << "    " << maior << endl;
    }
}