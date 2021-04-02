#include <iostream>
#include <vector>
#include <queue>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define par pair<int, int>

using namespace std;

priority_queue<par> maior;
priority_queue<par, vector<par>, greater<par> > menor;
int n, k, x[200009], i;
long long res, soma;
int main()
{_
    while (cin >> n >> k)
    {
        soma = 0;

        for (i = 1; i <= n; i++)
        {
            cin >> x[i];
            menor.push(mp(x[i], i));
            maior.push(mp(x[i], i));
            soma += x[i];

            if (i == k)
            {
                res = soma - menor.top().first - maior.top().first;
            }
            else if (i > k)
            {
                soma -= x[i - k];

                while (menor.top().second <= i - k)
                    menor.pop();

                while (maior.top().second <= i - k)
                    maior.pop();

                res += soma - menor.top().first - maior.top().first;
            }
        }

        while (!menor.empty()) menor.pop();
        while (!maior.empty()) maior.pop();

        std::cout << res << endl;
    }

    return 0;
}