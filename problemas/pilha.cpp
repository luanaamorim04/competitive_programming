#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    int n;
    while(1)
    {
        queue<int> cards;
        cin >> n;
        if (n == 0) return 0;
        cout << "Discarded cards: ";
        for (int i = 0; i < n; i++)
        {
            cards.push(i + 1);
        }

        while (cards.size() > 1)
        {
            cout << cards.front();
            if (cards.size() > 2) cout << ", ";
            cards.pop();
            cards.push(cards.front());
            cards.pop();
        }
        cout << "\nRemaining card: " << cards.front() << endl;
    }
}