#include<bits/stdc++.h>
#define INF 1e9
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x) & (-x))
#define ii pair<int,int>
#define INF 1e9+1
using namespace std;
typedef long long int ll;

struct vetor
{
    double x, y;

    vetor operator +(vetor q) const
    {
        return {x + q.x, y + q.y};
    }
    vetor operator -(vetor q) const
    {
        return {x - q.x, y - q.y};
    }
    double operator ~() const 
    {
        return hypot(x, y);
    }
    double operator *(vetor q) const 
    {
        return (x*q.x + y*q.y);
    }
    double operator ^(vetor q) const 
    {
        return (x*q.y - y*q.x);
    }
};

double f(vetor p, vetor q, vetor r)
{
    return fabs((r-p)^(q-p))/(~(q-p));
}

vetor C, X, Y;
double N, ans, R;

int main()
{_
    cin >> N >> C.x >> C.y >> R;

    while (N--)
    {
        cin >> X.x >> X.y >> Y.x >> Y.y;
        ans += (f(X,Y,C)<=R);
    }

    cout << ans << endl;
}

