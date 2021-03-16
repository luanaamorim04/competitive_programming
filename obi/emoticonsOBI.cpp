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

int happy, sad, t;
string m;

int main()
{_
    getline(cin, m);
    for (int i = 0; i < m.size(); i++)
    {
        if (m[i] == ':')
        {
            t = 1;
        }
        else if (m[i] == '-' && t == 1)
        {
            t = 2;
        }
        else if (m[i] == ')' && t == 2)
        {
            happy++;
            t = 0;
        }
        else if (m[i] == '(' && t == 2)
        {
            sad++;
            t = 0;
        }
        else
        {
            t = 0;
        }
    }

    if (sad == happy)
    {
        cout << "neutro" << endl;
    }
    else if (sad > happy)
    {
        cout << "chateado" << endl;
    }
    else
    {
        cout << "divertido" << endl;
    }
    
}