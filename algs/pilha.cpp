#include <iostream>
#include <stack>

using namespace std;

stack<char> pilha;
int n, ok;
string s;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> s;
        ok = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                pilha.push(s[i]);
                continue;
            }

            if (s[i] == '}')
            {
                if (pilha.top() == '{') pilha.pop();
                else ok = 0;
            }
            else if (s[i] == ')')
            {
                if (pilha.top() == '(') pilha.pop();
                else ok = 0;
            }
            else
            {
                if (pilha.top() == '[') pilha.pop();
                else ok = 0;
            }
        }

        if (!pilha.empty()) ok = 0;
        while (!pilha.empty()) pilha.pop();

        cout << (ok ? 'S' : 'N') << endl;
    }
}