#include <iostream>
#include <stack>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define mp make_pair

//teste

using namespace std;

int main()
{_
    long long n, x, largest, index, i;
    stack<pair<long long, long long> > size;
    while (cin >> n && n)
    {
        largest = 0;
        cin >> x;
        size.push(mp(x, 0));
        for (i = 1; i < n; i++)
        {
            cin >> x;
            if (x > size.top().first)
            {
                if (largest < size.top().first * abs(i - size.top().second))
                    largest = size.top().first * abs(i - size.top().second);
                size.push(mp(x, i));
            }
            else if (x < size.top().first)
            {    
                while (!size.empty() && x < size.top().first)
                {
                    if (largest < size.top().first * abs(i - size.top().second))
                        largest = size.top().first * abs(i - size.top().second);

                    index = size.top().second;
                    size.pop();
                }

                size.push(mp(x, index));
            }
        }

        while (!size.empty())
        {
            if (largest < size.top().first * (n - size.top().second))
                largest = size.top().first * (n - size.top().second);

            size.pop();
        }

        cout << largest << endl;
    }
}