#include <iostream>

using namespace std;

int arr[101], n, k, x;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > k) 
        {
            x = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > k) 
        {
            x = i - x + 1;
            break;
        }
    }

    cout << n - x << endl;
}