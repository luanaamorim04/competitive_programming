#include "cave.h"
#include <iostream>
#define dbug(x) cout << (#x) << " -> " << x << endl
#define ll long long
#define INF (1e9)
#define MAX (int) (5e3 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl

using namespace std;

int resp1[MAX], resp2[MAX], tem[MAX], tam, pos[MAX];

void change(int l, int r)
{
    for (int k = l; k <= r; k++)
        if (!tem[k]) resp1[k] ^= 1;
}

void exploreCave(int n)
{
    for (int i = 0; i < n; i++)
    {
        // dbug(i);
        int idx = tryCombination(resp1);
        if (idx > i || idx == -1)
            change(0, n-1);


        // dbug(idx);
        // for (int j = 0; j < n; j++)
        //     cout << resp1[j] << ' ';
        // cout << endl;


        int ini = 0, meio, fim = n-1, k;
        while (ini != fim)
        {
            meio = (ini+fim)>>1;
            change(ini, meio);
            k = ini;
            // dbug(ini);
            // dbug(meio);
            // dbug(tryCombination(resp1));
            int idx = tryCombination(resp1);
            if (idx > i || idx == -1) fim = meio;
            else ini = meio + 1;
            change(k, meio);
        }

        resp2[i] = fim;
        pos[fim] = i;
        tem[fim] = 1;
        resp1[fim] ^= 1;
        // cout << endl;
    }

    answer(resp1, pos);
}