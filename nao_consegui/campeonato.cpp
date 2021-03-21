#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int c, b;

int f(int x, int y)
{
    if (x < c && c > 1) return 1;
    if (c == 1) return 0;
    return f(x/c + x%c, y + x/c);
}

int main()
{_
   cin >> c >> b;
   int ini = 1, fim = 1000000009, meio;

    while (ini <= fim)
    {
        meio = ini+(fim-ini)/2;

        int x = f(meio, 0);
        if (x == b) 
        {
            cout << meio << endl;
            return 0;
        }
        else if (x < b) ini = meio + 1;
        else fim = meio - 1;
    }
}