#include <iostream>
#include <string.h>

using namespace std;

int faces[200020], res[100020];

int main()
{
    int n;
    cin >> n;
    memset(faces + 2, 1, n);

    for (int i = 0; i < n; i++)
        cout << faces[i] << endl;
}