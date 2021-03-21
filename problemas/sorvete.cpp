#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int praia[10009], a, b, n, m, k;

int main()
{_  
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        praia[a]++;
        praia[b]--;
    }

    for (int i = 0; i <= n + 1; i++)
    {
        if (i) praia[i] += praia[i - 1];
        if (praia[i] && !k)
        {
            cout << i << ' ';
            k = 1;
        }
        else if (!praia[i] && k)
        {
            cout << i << endl;
            k = 0;
        }
    }
}