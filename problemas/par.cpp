#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#define INF 99999999
#define MOD 1000000007
#define MAXN 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s;
queue<char> par, impar;

int main()
{_  
    cin >> s;
    for (int i = 0; i < s.size(); i++) 
    {
        (s[i] % 2 ? impar : par).push(s[i]);
    }

    while (!par.empty())
    {
        cout << par.front();
        par.pop();
    }

    while (!impar.empty())
    {
        cout << impar.front();
        impar.pop();
    }
    
}