#include <iostream>
#include <algorithm>

using namespace std;

long long n, memo[200009];
pair<long long, pair<long long, long long> > p[200009];

int bb(long long x)
{
    int ini = 0, fim = n - 1, meio;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;
        if (p[meio].first > x) fim = meio - 1;
        else if (p[meio].first < x) ini = meio + 1;
        else
        {
            while (p[meio].first == x)
                meio++;
            return meio;
        }
    }

    return fim + 1;
}

long long f(int idx)
{
    if (memo[idx] != -1) return memo[idx];
    int next = bb(p[idx].second.first);
    return memo[idx] = max(f(next) + p[idx].second.second, f(idx + 1));
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second.first >> p[i].second.second;
        memo[i] = -1;
    }

    sort(p, p+n);

    cout << f(0) << endl;
}