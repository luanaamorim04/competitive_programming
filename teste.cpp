#include <iostream>
#include <queue>
#include <vector>
#define MAXN (int) (1e5 + 10)

using namespace std;

vector <int> grafo[MAXN];
queue <int> fila;
vector <pair <int, int>> arestas;//guardará as arestas que serão criadas entre os vértices
int n, m, a, b, vis[MAXN], comp, last;//last será a última componente percorrida, enquanto i será a atual 

int main() {
  cin >> n >> m;
  while (m--)
  {
    cin >> a >> b;
    grafo[a].push_back(b);
    grafo[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) 
  {
    if (vis[i] == 1) continue;

    if (i != 1)
      arestas.push_back({last, i});

    last = i;
    comp++;
    fila.push(i);
    
     while (!fila.empty())
     {
       
      int u = fila.front(); fila.pop();
      if (vis[u]== 1) continue;
      vis[u] = 1;
       
      for (int v: grafo[u])
      {
       if (vis[v]!= 1) fila.push(v);     
      }
    }
  }

  cout << comp - 1 << endl;
  for (auto[a, b] : arestas) 
    cout << a << ' ' << b << endl;
  
}