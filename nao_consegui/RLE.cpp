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

string s;
int qnt, last, r[100009];

int main()
{_  
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9') qnt = qnt*10 + (s[i] - '0');
        else if (s[i - 1] == '*')
        { 
            r[last] = (int) s[i];
            r[last + qnt] = (int) s[i];
            qnt = 0;
            last += qnt;
        }
    }
    for (int i = 1; i <= last; i++)
    {
        cout << (char) r[i - 1];
    }
    cout << endl;
}