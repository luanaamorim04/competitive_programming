#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s;
int n, letra, sp;

int main()
{_
    while (cin >> n)
    {
        getline(cin, s);
        while (n--)
        {
            getline(cin, s);
            sp = 0; letra = 0;
            for (int i = 0; i < s.size(); i++)
            {
                sp += (s[i] == ' ');
                if (s[i] == '.') letra++;
                else letra = 0;
            }

            cout << (char) (letra + 'a' + (sp*3) - 1) << endl;
        }
    }
}