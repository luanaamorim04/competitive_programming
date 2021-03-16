#include <iostream>
#include <vector>
#include <stack>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

string s;
map<char, int> val;
stack<char> pilha;

int main()
{_
    int n;
    cin >> n;
    val['+'] = 1;
    val['-'] = 1;
    val['*'] = 2;
    val['/'] = 2;
    val['^'] = 3;
    val['('] = 4;
    val[')'] = 4;
    while (n--)
    {
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (val[s[i]] == 0)
            {
                cout << s[i];
            }
            else if (s[i] != ')')
            {
                while (!pilha.empty() && val[s[i]] <= val[pilha.top()])
                {
                    if (pilha.top() == '(') break;
                    
                    cout << pilha.top();
                    pilha.pop();
                }

                pilha.push(s[i]);
            }
            else 
            {
                while(!pilha.empty())
                {
                    if (pilha.top() == '(')
                    {
                        pilha.pop();
                        break;
                    }
                    cout << pilha.top();
                    pilha.pop();
                }
            }
        }

        while(!pilha.empty())
        {
            cout << pilha.top();
            pilha.pop();
        }
        cout << '\n';
    }
}