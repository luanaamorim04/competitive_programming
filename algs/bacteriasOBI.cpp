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

int log_10[50000], resto[50000], n, a, b;

void fexpo(int a, int b, int i)
{
    int resp = 1, l, r, ans = 0;
    while (b)
    {
        if (b % 2) resp = resp * a;
        a = a * a;
        while (a >= 10)
        {
            a /= 10;
            ans++;
        }
        while (resp >= 10)
        {
            resp /= 10;
            ans++;
        }
        b /= 2;
    }

    log_10[i] = ans;
    resto[i] = resp;
}

int main()
{_  
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        fexpo(a, b, i);
        cout << log_10[i] << ' ' << resto[i] << endl;
    }
}