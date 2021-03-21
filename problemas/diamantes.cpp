#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> mina;
stack<int> tmp;

int main()
{
    int n, ok, res;
    string s;
    cin >> n;
    while (n--)
    {
        ok = 1;
        res = 0;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '<') mina.push(1);
            else if (s[i] == '>' && !mina.empty())
            {
                mina.pop();
                res++;
            }
        }
        mina = tmp;
        cout << res << '\n';
    }
}