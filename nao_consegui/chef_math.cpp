#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int fib[45], n, K, ok, S;

void f(int idx, int soma)
{
    if (soma == S && idx == K) ok++;
    if (idx == K || soma >= S) return;
    
    for (int i = 1; i <= n; i++)
        f(idx + 1, soma + fib[i]);
}

void ini()
{
    n = 44;
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
}

int main()
{_
    ini();
    cin >> K >> S;
    f(0, 0);
    cout << ok << endl;        
}