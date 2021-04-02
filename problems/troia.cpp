#include <iostream>
#include <vector>

using namespace std;

#define MAXN 50050

int n, m;
int componente[MAXN];
vector<int> lista[MAXN];

void dfs(int x)
{

	for(int i = 0;i < (int)lista[x].size();i++)
    {
		
		int v = lista[x][i];
		
		if(componente[v] == -1)
        { 
			componente[v] = componente[x];
			dfs(v);
		}
	}
}

int main(){
	
	cin>>n>>m;

	for(int i = 1;i <= n;i++) componente[i] = -1;
	for(int i = 1;i <= m;i++)
    {

		int a, b;
		cin>>a>>b;

		lista[a].push_back(b);
		lista[b].push_back(a);
	}
	
	int numero_componentes = 0;

	for(int i = 1;i <= n;i++)
    {

		if(componente[i] == -1)
        { 
			numero_componentes++;
			componente[i] = numero_componentes;
			dfs(i);
		}
	}
	
	cout<<numero_componentes<<"\n"; 
	return 0;
}
