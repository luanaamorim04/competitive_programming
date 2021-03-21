#include <iostream>
#include <vector>
#include <queue>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);


using namespace std;

int mdc (int a, int b)
{
    if (b == 0) return a;
    return mdc(b, a % b);
}

int main()
{
    double a, b, c, m1, m2, m3, MDC, min = 100000, out[2];
    double media;
    cin >> a >> b >> c;

    MDC = mdc(b, c);
    if (b / MDC > a || c / MDC > a)
    cout << "IMPOSSIVEL";
    else 
    cout << b / MDC << ' ' << c /  MDC;



}