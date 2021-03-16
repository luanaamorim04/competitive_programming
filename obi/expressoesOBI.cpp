#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<char> res;
stack<char> emp;
int n, ok;
string s;

int main()
{
    cin >> n;
    while (n--)
    {
        ok = 1;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                res.push(s[i]);

            if (s[i] == ')')
            {
                if (res.empty() || res.top() != '(') ok = 0;
                else res.pop();
            }
            if (s[i] == ']')
            {
                if (res.empty() || res.top() != '[') ok = 0;
                else res.pop();
            }
            if (s[i] == '}')
            {
                if (res.empty() || res.top() != '{') ok = 0;
                else res.pop();
            }

            if (ok == 0) break;
        }

        if (!res.empty())
        {
            ok = 0;
            res = emp;
        }

        if (ok == 0) cout << "N\n";
        else cout << "S\n";
    }
}