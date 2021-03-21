#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> pilha;
stack<int> menor;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    
    int n, x, i = 0;
    string s;
    menor.push(1000000009);
    cin >> n;
    while (n--)
    {
        cin >> s;
        s = s[1];
        if (s == "U")
        {
            i++;
            cin >> x;
            pilha.push(x);
            menor.push(min(x, menor.top()));
        }
        else if (s == "O" && i > 0)
        {
            i--;
            pilha.pop(); menor.pop();
        }
        else if (i > 0)
        {
            cout << menor.top() << '\n';
        }
        else
        {
            cout << "EMPTY\n";
        }
    }
}