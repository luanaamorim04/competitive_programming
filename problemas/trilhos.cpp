#include <iostream>
#include <vector>
#include <stack>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int n, x[1009], atual;
stack<int> estacao;


int main()
{
    while (cin >> n)
    {
        if (n == 0) return 0;
        while (1)
        {
            atual = 0;
            for (int i = 0; i < n; i++)
            {
                cin >> x[i];
                if (x[i] == 0) break;

                estacao.push(i);
                while (!estacao.empty() && estacao.top() == x[atual] - 1)
                {
                    atual++;
                    estacao.pop();
                }
            }

            if (!x[0]) break;
            if (estacao.empty()) cout << "Yes\n";
            else
            {
                while (!estacao.empty()) estacao.pop();
                cout << "No\n";
            }
        }

        cout << endl;
    }
}