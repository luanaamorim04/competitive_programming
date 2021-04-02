#include <iostream>
#include <utility>
#include <map>

using namespace std;

int main()
{
    string murderer, dead;
    map<string, int> hall;
    while (cin >> murderer >> dead)
    {
        if (hall[murderer] > -2) hall[murderer]++;
        hall[dead] = -3;
    }

    cout << "HALL OF MURDERERS\n";
    for (map<string,int>::iterator it = hall.begin(); it != hall.end(); it++)
    {
        string i = it->first;
        int j = it->second;
        if (j > -2) cout << i << ' ' << j << '\n';
    }
}