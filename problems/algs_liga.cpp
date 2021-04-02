#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int num, pos, res;
stack<int> dig;

int main()
{
    cin >> num;
    while (num > 0)
    {
        dig.push(num % 10);
        num /= 10;
    }

    while (!dig.empty())
    {
        res += min(abs(9 - max(pos, dig.top()) + min(pos, dig.top())) + 1, abs(pos - dig.top()));
        pos = dig.top();
        dig.pop();
    }

    cout << res << endl;
    return 0;
}