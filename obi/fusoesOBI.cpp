#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 100009
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, ans, pai[MAX], tam[MAX];
char q;

int id(int x)
{
    if (x == pai[x]) return x;
    return pai[x] = id(pai[x]);
}

void join(int a, int b)
{
    if (tam[a] > tam[b])
    {
        int tmp = a; a = b; b = tmp;
    }
    pai[a] = b;
    tam[b] += tam[a]; 
}   

int main()
{_
    while (cin >> n >> m && n)
    {    
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            pai[i] = i;
            tam[i] = 1;
        }
        while (m--)
        {
            cin >> q >> a >> b;
            a = id(a), b = id(b);
            if (q == 'F')
            {
                join(a, b);
            }
            else
            {
                cout << (a == b ? 'S' : 'N') << endl;
            }
        }
    }
}