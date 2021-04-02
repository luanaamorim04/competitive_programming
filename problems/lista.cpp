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

int n, m, t;
char c;

int main()
{_  
    cin >> n >> m;
    while (m--)
    {
        cin >> c;
        if (c =='R') t = max(t - 1, 0);
        else t = min(t + 1, m);
        if (t == 0) cout << "Lista Vazia\n";
        if (t == m) cout << "Lista Cheia\n";
    }
}