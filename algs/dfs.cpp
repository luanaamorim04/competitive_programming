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