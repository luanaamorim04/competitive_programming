#include <iostream>
#include <map>
#include <vector>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr, q, a, b, num;
map<int, vector<int> > pos;

// maior ou igual a A;
int buscaA(int N, int x)
{
    int ini = 0, meio, fim = pos[x].size() - 1, ans = -1;
    while (ini <= fim)
    {
        meio = (fim + ini) / 2;
        if (pos[x][meio] >= N)
        {
            ans = meio;
            fim = meio - 1;
        }
        else
        {
            ini = meio + 1;
        }
    }

    return ans;
}

// menor ou igual a B;
int buscaB(int N, int x)
{
    int ini = 0, meio, fim = pos[x].size() - 1, ans = pos.size();
    while (ini <= fim)
    {
        meio = (fim + ini) / 2;
        if (pos[x][meio] >= N)
        {
            ans = meio;
            fim = meio - 1;
        }
        else
        {
            ini = meio + 1;
        }
    }

    return pos[x][meio] == N ? ans : ans - 1;
}

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr;
        pos[arr].push_back(i);
    }

    cin >> q;

    while (q--)
    {
        cin >> a >> b >> num;
        cout << buscaB(b, num) - buscaA(a, num) + 1 << endl;
    }

    return 0;
}