#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<char> res;
pair<int, int> a;

int main()
{
    int x = 63, y = 65;

    for (int i = 0; i < 15; i++)
    {
        cin >> a.first >> a.second;
        if (i < 8)
        {
            x += 2;
            y = x + 1;
            if (a.first > a.second) res.push(x);
            else res.push(y);
        }
        else
        {
            if (a.first > a.second)
            {
                res.push(res.front());
                res.pop();
                res.pop();
            }
            else
            {
                res.pop();
                res.push(res.front());
                res.pop();
            }
        }
    }

    cout << (char) res.front();
}