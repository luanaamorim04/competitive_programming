#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <stack>
#include <cmath> 
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, d;
char dig;
stack<char> pilha;

int main()
{_
    while (cin >> n >> m && (n || m))
    {
        d = 0;
        vector<char> v;
        while (n--)
        {
            cin >> dig;
            while (!pilha.empty() && d < m && pilha.top() < dig)
            {
                pilha.pop();
                d++;
            }

            pilha.push(dig);
        }

        while (d < m)
        {
            d++;
            pilha.pop();
        }

        while (!pilha.empty())
        {
            v.push_back(pilha.top());
            pilha.pop();
        }

        for (int i = v.size() - 1; i >= 0; i--)
            cout << v[i];

        cout << endl;
    }
}