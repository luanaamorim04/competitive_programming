#include <stdio.h>

int res[100005][100005] = {}, out[100000];

int main(void)
{
    int n, m, t, x, y, index = 0;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &t, &x, &y);

        if (t == 1)
        {
            res[x][y] = 1;
            res[y][x] = 1;
        }
        else 
        {
            out[index] = res[x][y];
            index++;
        }
    }

    for (int i = 0; i < index; i++)
        printf("%i\n", out[i]);

}