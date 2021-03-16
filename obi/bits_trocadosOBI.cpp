#include <iostream>

using namespace std;

int n, k, t;

int main()
{
	while (cin >> n && n)
    {
        cout << "Teste " << ++t << endl; 
        k = 0;
        while (n >= 50)
        {
            n -= 50;
            k++;
        }

        cout << k << ' ';
        k = 0;

        while (n >= 10)
        {
            n -= 10;
            k++;
        }

        cout << k << ' ';
        k = 0;

        while (n >= 5)
        {
            n -= 5;
            k++;
        }

        cout << k << ' ';
        k = 0;

        while (n)
        {
            n--;
            k++;
        }

        cout << k << endl;
    }
}
