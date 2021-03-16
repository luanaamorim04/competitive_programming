#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <unordered_map>
#define INF 99999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

unordered_map<string, string> last;
string ori, dest, a, b, c, f;
queue<string> fila;
unordered_map<string, int> nivel;

void vertices(string f);
void print_ans(string v);

int main()
{_
    for (int i = 0; i < 9; i++)
        dest += (i + 1) % 9 + '0';

    while (cin >> a >> b >> c)
    {
        ori = a; ori += b; ori += c;

        nivel.clear();
        while (!fila.empty()) fila.pop();
        fila.push(ori);
        last[ori] = ori;
        nivel[ori] = 1;
        while (!fila.empty())
        {
            f = fila.front(); fila.pop();
            if (f == dest) break;
            vertices(f);
        }

        if (nivel[dest] < 2) 
        {
            cout << "Problema sem solucao" << endl;
        }
        else
        {
            cout << "Quantidade minima de passos = " << nivel[dest] - 1 << endl;
            print_ans(dest);
        }
    }
}

void print_ans(string v)
{
    if (last[v] != ori) print_ans(last[v]);
    for (int i = 1; i <= 9; i++)
    {
        cout << v[i - 1];
        if (i % 3 == 0) cout << endl;
    }
    if (v != dest) cout << endl;
}

void vertices(string f)
{
    string v = f;
    int x;
    for (int i = 0; i < 9; i++)
        if (f[i] == '0') x = i;

    if (x > 2)
    {
        swap(v[x], v[x - 3]);
        if (nivel[v] < 1)
        {
            nivel[v] = nivel[f] + 1;
            fila.push(v);
            last[v] = f;
        }
        swap(v[x], v[x - 3]);
    }
    if (x < 6)
    {
        swap(v[x], v[x + 3]);
        if (nivel[v] < 1)
        {
            nivel[v] = nivel[f] + 1;
            fila.push(v);
            last[v] = f;
        }
        swap(v[x], v[x + 3]);
    }
    if (x % 3 != 2)
    {
        swap(v[x], v[x + 1]);
        if (nivel[v] < 1)
        {
            nivel[v] = nivel[f] + 1;
            fila.push(v);
            last[v] = f;
        }
        swap(v[x], v[x + 1]);
    }
    if (x % 3)
    {
        swap(v[x], v[x - 1]);
        if (nivel[v] < 1)
        {
            nivel[v] = nivel[f] + 1;
            fila.push(v);
            last[v] = f;
        }
        swap(v[x], v[x - 1]);
    }
}