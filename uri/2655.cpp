#include <algorithm>
#include <iostream>
#include <cstring>
#define par pair<int, int>
#define y first
#define x second

using namespace std;

int n, resp, a, b, memo[101];
par pontos[101];

int cross(par a, par b, par c)
{
    int dx1 = a.x-b.x, dy1 = a.y-b.y, dx2 = c.x-b.x, dy2 = c.y-b.y;
    return dx1*dy2 - dy1*dx2;
}

int f(int k)
{
    int ans = 1;
    if (~memo[k]) return memo[k];
    
    for (int i = k + 1; i < n; i++)
        if (cross(make_pair(0, a), pontos[i], pontos[k]) < 0 && cross(make_pair(0, b), pontos[i], pontos[k]) > 0)
        {
            ans = max(ans, f(i) + 1);
        }

    return memo[k] = ans;
}

int main()
{
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        cin >> pontos[i].x >> pontos[i].y;

    sort(pontos, pontos+n, greater<par>());
    memset(memo, -1, sizeof(memo));

    for (int i = 0; i < n; i++)
        resp = max(resp, f(i));

    cout << resp << endl;
}