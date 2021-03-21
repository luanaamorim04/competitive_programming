#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 9999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, passou[16];
double memo[16][101];

struct pizza
{
    double weight, price;
    vector<par> promo;
};

pizza pizzas[16];

double f(int idx, int desc)
{
    if (idx > n) return INF;
    if (memo[idx][desc] != -1) return memo[idx][desc];

    double k = (100 - desc) / (double) 100;
    if (passou[idx])
    passou[idx] = 1;
    double ans = (pizzas[idx].price * k) / (double) pizzas[idx].weight;

    for (int i = 0; i < pizzas[idx].promo.size(); i++)
    {
        int j = pizzas[idx].promo[i].first;
        int p = pizzas[idx].promo[i].second;
        ans = min(ans, (ans + f(j, p)) / 2);
    }

    passou[idx] = 0;
    return memo[idx][desc] = min(min(ans, f(idx + 1, 0)), (ans + f(idx + 1, 0)) / (double) 2);
}

int main()
{_  
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pizzas[i].price >> pizzas[i].weight >> m;
        while (m--)
        {
            cin >> a >> b;
            pizzas[i].promo.push_back(par(a, b));
        }
    }

    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 101; j++)
            memo[i][j] = -1;

    cout << fixed << setprecision(4) << f(1, 0) << endl;
}