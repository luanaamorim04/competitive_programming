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

string a, b, c;

int main()
{_  
    cin >> a >> b;
    if (a != "Reluew" && b != "Reluew") 
    {
        cout << "Nao eh possivel descriptografar!";
        return 0;
    }
    if (a != "Markinhos" && b != "Markinhos") 
    {
        cout << "Nao eh possivel descriptografar!";
        return 0;
    }

    int n;
    cin >> n;
    cin >> c;
    for (int i = 0; i < c.size(); i++)
        cout << (char) (c[i] + n);
    cout << endl;
}