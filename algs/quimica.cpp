#include <iostream>
#include <stack>

using namespace std;

int eletrons;
stack<int> p;
int arr[] = {2, 2, 6, 2, 6, 2, 10, 6, 2, 10, 6, 2, 14, 10, 6, 2, 14, 10, 6};
string resp[] = {"1s", "2s", "2p", "3s", "3p", "4s", "3d", "4p", "5s", "4d", "5p", "6s", "4f", "5d", "6p", "7s", "5f", "6d", "7p"};
string num[] = {"⁰", "¹", "²", "³", "⁴", "⁵", "⁶", "⁷", "⁸", "⁹"};

int main()
{
    int idx = 0;
    cin >> eletrons;
    while (eletrons)
    {
        int t;
        if (eletrons >= arr[idx]) t = arr[idx];
        else t = eletrons;

        eletrons -= t;

        while (t)
        {
            int dig = t % 10;
            p.push(dig);
            t /= 10;
        }

        cout << resp[idx];
        while (p.size())
        {
            cout << num[p.top()];
            p.pop();
        }
        cout << ' ';
        idx++;
    }

    cout << endl;
}